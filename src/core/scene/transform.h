//
// Created by Kimera Royal on 25/01/2024.
//

#pragma once

#include <vector>

#include <glm/vec3.hpp>
#include <glm/gtc/quaternion.hpp>

namespace bombengine
{
    class Transform
    {
private:
		Transform* m_parent;
		std::vector<Transform*> m_children;

		glm::vec3 m_position;
		glm::quat m_rotation;
		glm::vec3 m_scale;

		mutable glm::mat4 m_localModelMatrix;
		mutable bool m_localModelMatrixDirty;

		mutable glm::mat4 m_modelMatrix;
		mutable bool m_modelMatrixDirty;

		void AddChild(Transform* _child);

		void MarkDirty();
	public:
		explicit Transform(glm::vec3 _position, glm::quat _rotation, glm::vec3 _scale);
		explicit Transform(glm::vec3 _position, glm::vec3 _eulerAngles, glm::vec3 _scale);
    	
		void Move(const glm::vec3 _amount) { SetPosition(m_position + _amount); }
		void Rotate(const glm::quat _amount) { SetRotation(m_rotation * _amount); }
		void Rotate(const glm::vec3 _amount) { Rotate(glm::quat(glm::radians(_amount))); }

		[[nodiscard]] Transform* GetParent() const { return m_parent; }
		[[nodiscard]] Transform* GetChild(unsigned int _index) const;
		void SetParent(Transform* _parent);

		[[nodiscard]] glm::mat4 GetLocalModelMatrix() const;
		[[nodiscard]] glm::mat4 GetModelMatrix() const;

    	[[nodiscard]] inline glm::vec3 GetPosition() const { return m_position; }
    	void SetPosition(const glm::vec3 _position)
    	{
    		m_position = _position;
    		MarkDirty();
    	}

    	[[nodiscard]] inline glm::quat GetRotation() const { return m_rotation; }
    	void SetRotation(const glm::quat _rotation)
		{
			m_rotation = _rotation;
			MarkDirty();
		}

    	[[nodiscard]] inline glm::vec3 GetEulerAngles() const { return glm::degrees(glm::eulerAngles(m_rotation)); }
    	void SetEulerAngles(const glm::vec3 _eulerAngles)
    	{
    		glm::vec3 eulerModulo = _eulerAngles + 180.0f;
    		for(auto i = 0; i < 3; i++)
    		{
    			eulerModulo[i] = fmodf(eulerModulo[i], 360.0f);
    		}
    		m_rotation = glm::quat(glm::radians(eulerModulo - glm::vec3(180.0f)));
    		MarkDirty();
    	}

    	[[nodiscard]] inline glm::vec3 GetScale() const { return m_scale; }
    	void SetScale(const glm::vec3 _scale)
    	{
    		m_scale = _scale;
    		MarkDirty();
    	}

		[[nodiscard]] inline glm::vec3 GetLeft() const { return normalize(glm::vec3(GetModelMatrix()[0])); }
		[[nodiscard]] inline glm::vec3 GetUp() const { return normalize(glm::vec3(GetModelMatrix()[1])); }
		[[nodiscard]] inline glm::vec3 GetForward() const { return -normalize(glm::vec3(GetModelMatrix()[2])); }
	};
} // bombengine
