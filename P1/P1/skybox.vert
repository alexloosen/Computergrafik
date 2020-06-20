#version 330 core
#extension GL_ARB_explicit_uniform_location : enable
#extension GL_ARB_seperate_shader_objects : enable

in vec3 aPos;
out vec3 vCubeDir;
layout (location = 0) uniform mat4 uProjection;
layout (location = 1) uniform mat4 uView;

void main(void)
{
    vCubeDir = aPos;
    gl_Position = uProjection * uView * vec4(aPos, 1.0);
}
