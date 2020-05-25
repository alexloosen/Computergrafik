#version 330 core
#extension GL_ARB_explicit_uniform_location : enable
#extension GL_ARB_seperate_shader_objects : enable

layout(location = 0) in vec2 aPosition;
layout(location = 1) in vec3 aColor;
layout(location = 2) in vec2 aTexPosition;

out vec3 vColor;
out vec2 vTexPosition;

layout(location = 7) uniform float uTexOffset;

void main()
{
    vColor = aColor;
    vTexPosition = aTexPosition + uTexOffset;
    gl_Position = vec4(aPosition, 0.0, 1.0);
}
