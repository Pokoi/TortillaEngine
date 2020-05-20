#version 330

uniform float   light_intensity;
uniform vec3    light_color;
uniform vec3    light_position;

uniform float   ambient_intensity = 0.2;
uniform float   diffuse_intensity = 0.8;
        
uniform mat4 model_view_matrix;
uniform mat4 projection_matrix;
uniform mat4 model_normal_matrix;
        
uniform vec3 material_color(1.0,1.0,1.0);
        
layout (location = 0) in vec3 vertex_coordinates;
layout (location = 1) in vec3 vertex_normal;
        
out vec3 front_color;
        
void main()
{
    vec4  normal   = model_normal_matrix * vec4(vertex_normal, 1.0);
    vec4  position = model_view_matrix * vec4(vertex_coordinates, 1.0);
        
    vec4  light_direction = light_position - position;
    float light_intensity = diffuse_intensity * max (dot (normalize (normal.xyz), normalize (light_direction.xyz)), 0.0);
        
    front_color = ambient_intensity * material_color + diffuse_intensity * light_intensity * light_color * material_color;
    gl_Position = projection_matrix * position;
}