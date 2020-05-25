#version 330 core
#extension GL_ARB_explicit_uniform_location : enable
#extension GL_ARB_seperate_shader_objects : enable

layout(location = 0) in vec3 aPosition;
layout(location = 1) in vec3 aNormal;
layout(location = 2) in vec2 aTexPosition;

out vec3 vNormal;
out vec2 vTexPosition;

layout(location = 0) uniform mat4 uCamera;
layout(location = 1) uniform mat4 uProjection;
layout(location = 2) uniform mat4 uModel;

void main()
{
    vNormal = aNormal;
    vTexPosition = aTexPosition;

    vec4 pos = vec4(aPosition, 1.0);
    gl_Position = pos * uModel * uCamera;// * uProjection; //* uProjection * uCamera * uModel;
}
