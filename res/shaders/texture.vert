#version 330 core

layout (location = 0) in vec3 vertex_position;
layout (location = 1) in vec2 texture_coord;

uniform mat4 model;
uniform mat4 view = mat4(1.0);

out vec2 tex_coord;

void main() {
	mat4 transform = view * model;
	gl_Position = transform * vec4(vertex_position.xyz, 1.0);
    tex_coord = texture_coord;
}