#ifndef _MATHS_H_
#define _MATHS_H_

#include "misc/glm/glm.hpp"
#include "misc/glm/ext.hpp"

using namespace glm;

#define PERSPECTIVE_MATRIX (perspective(glm::radians(60.0f), ((1.0f * 1920) / (1.0f * 1080)), 0.1f, 10000.0f))

#define ORTHOGRAPHIC_MATRIX (ortho(0.0f, (float)1920, 0.0f, (float)1080, 0.0f, 1.0f))

#endif // !_MATHS_H_
