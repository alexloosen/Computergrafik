#version 330 core
#extension GL_ARB_explicit_uniform_location : enable
//#extension GL_ARB_seperate_shader_objects : enable

in vec3 vNormal;
in vec2 vTexPosition;

layout(location = 0) out vec4 fragColor;

layout(location = 5) uniform vec3 uColor;
layout(location = 6) uniform sampler2D uTex0;

void main()
{
    vec2 uvCoordinates = vTexPosition;

    vec4 color = texture(uTex0, uvCoordinates);

    fragColor = vec4(uColor, 1.0);
}
