#version 330 core
#extension GL_ARB_explicit_uniform_location : enable
#extension GL_ARB_seperate_shader_objects : enable

layout(location = 0) in vec3 aPosition;
layout(location = 1) in vec3 aNormal;
layout(location = 2) in vec2 aTexPosition;

out vec2 vTexPosition;
out vec3 vNormal;
out vec3 vFragPos;

layout(location = 0) uniform mat4 uCamera;
layout(location = 1) uniform mat4 uProjection;
layout(location = 2) uniform mat4 uModel;

void main()
{
    gl_Position = uProjection * uCamera * uModel * vec4(aPosition, 1.0);
    vFragPos = vec3(uCamera * uModel * vec4(aPosition, 1.0));
    vNormal = mat3(transpose(inverse(uModel))) * aNormal;
}
