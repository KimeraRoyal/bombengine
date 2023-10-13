//
// Created by Kimera Royal on 23/06/2023.
//

#pragma once

#include <vector>

#include "GL/glew.h"

namespace cpp_engine
{
	class ElementBuffer
	{
	private:
		GLuint m_id;

		std::vector<unsigned int> m_data;

		bool m_dirty;
	public:
		ElementBuffer();
		~ElementBuffer();

		void AddValue(unsigned int _value);

		[[nodiscard]] GLuint GetID();

		[[nodiscard]] inline unsigned int GetDataCount() const { return m_data.size(); }

	};
}
