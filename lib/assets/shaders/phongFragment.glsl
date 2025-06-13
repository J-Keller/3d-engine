#version 330 core

const int MAX_POINT_LIGHTS = 4;

in vec2 texCoord0;
in vec3 normal0;
in vec3 worldPos0;

out vec4 FragColor;

struct BaseLight {
    vec3 color;
    float intensity;
};

struct DirectionalLight {
    BaseLight base;
    vec3 direction;
};

struct PointLight {
    vec3 position;
    BaseLight base;
    float range;
    float constant;
    float linear;
    float quadratic;
};

struct SpotLight {
    PointLight pLight;
    vec3 direction;
    float cutOff;
};

uniform vec3 eyePos;

uniform vec3 baseColor;
uniform vec3 ambientLight;
uniform sampler2D sampler;

uniform float specularIntensity;
uniform float specularPower;

uniform DirectionalLight dLight;
uniform PointLight pLight[MAX_POINT_LIGHTS];
uniform SpotLight sLight;


vec4 calcLight(BaseLight base, vec3 direction, vec3 normal) {
    float diffuseFactor = dot(normal, -direction);

    vec4 diffuseColor = vec4(0, 0, 0, 0);
    vec4 specularColor = vec4(0, 0, 0, 0);

    if(diffuseFactor > 0) {
        diffuseColor = vec4(base.color, 1.0) * base.intensity * diffuseFactor;

        vec3 directionToEye = normalize(eyePos - worldPos0);
        vec3 reflectDirection = normalize(reflect(direction, normal));

        float specularFactor = dot(directionToEye, reflectDirection);
        specularFactor = pow(specularFactor, specularPower);

        if(specularFactor > 0) {
            specularColor = vec4(base.color, 1.0) * specularIntensity * specularFactor;
        }
    }

    return diffuseColor + specularColor;
}

vec4 calcDirectionalLight(DirectionalLight directionalLight, vec3 normal) {
    return calcLight(directionalLight.base, -directionalLight.direction, normal);
}

vec4 calcPointLight(PointLight pLight, vec3 normal) {
    vec3 lightDirection = worldPos0 - pLight.position;
    float distanceToPoint = length(lightDirection);

    if(distanceToPoint > pLight.range) {
        return vec4(0, 0, 0, 0);
    }

    lightDirection = normalize(lightDirection);

    vec4 color = calcLight(pLight.base, lightDirection, normal);

    float attenuation = pLight.constant + pLight.linear * distanceToPoint + pLight.quadratic * distanceToPoint * distanceToPoint + 0.0001;

    return color / attenuation;
}

vec4 calcSpotLight(SpotLight sLight, vec3 normal) {
    vec3 lightDirection = worldPos0 - sLight.pLight.position;
    lightDirection = normalize(lightDirection);

    float spotFactor = dot(lightDirection, sLight.direction);

    vec4 color = vec4(0, 0, 0, 0);

    if(spotFactor > sLight.cutOff) {
        color = calcPointLight(sLight.pLight, normal) * (1.0 - (1.0 - spotFactor)/(1.0 - sLight.cutOff));
    }

    return color;
}

void main() {
    vec4 totalLight = vec4(ambientLight, 1.0);
    vec4 color = vec4(baseColor, 1.0);
    vec4 textureColor = texture(sampler, texCoord0.xy);

    if(textureColor != vec4(0.0, 0.0, 0.0, 1.0)) color *= textureColor;

    vec3 normal = normalize(normal0);

    totalLight += calcSpotLight(sLight, normal);

    for(int i = 0; i < MAX_POINT_LIGHTS; i++) {
        if(pLight[i].base.intensity > 0) {
            totalLight += calcPointLight(pLight[i], normal);
        }
    }
    totalLight += calcDirectionalLight(dLight, normal);

    FragColor = color * totalLight;
}
