#version 330 core

layout (location = 0) in vec3 vertex_position;
layout (location = 1) in vec4 vertex_colour;

uniform mat4 model;
uniform mat4 view;

out vec4 colour;

void main() {
	mat4 transform = view * model;

	gl_Position = transform * vec4(vertex_position.xyz, 1.0);
	colour = vertex_colour;
}
