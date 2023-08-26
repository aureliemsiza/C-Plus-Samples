#include <iostream>
#include <vector>
#include <cmath>
#include <random>

class TerrainGenerator {
public:
    TerrainGenerator(int width, int height)
        : width(width), height(height), noiseGen(std::random_device()()) {}

    std::vector<std::vector<float>> GenerateTerrain(float scale, float amplitude) {
        std::vector<std::vector<float>> terrain(height, std::vector<float>(width, 0.0f));

        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                float noiseValue = GenerateNoise(x * scale, y * scale);
                terrain[y][x] = noiseValue * amplitude;
            }
        }

        return terrain;
    }

private:
    float GenerateNoise(float x, float y) {
        // Use Perlin noise or other noise algorithms here
        // Return a value between -1.0 and 1.0
    }

private:
    int width;
    int height;
    std::mt19937 noiseGen;
};

int main() {
    const int width = 100;
    const int height = 100;
    TerrainGenerator terrainGen(width, height);
    
    std::vector<std::vector<float>> terrain = terrainGen.GenerateTerrain(0.1f, 10.0f);

    // Use the generated terrain data for rendering or gameplay logic
    // ...
    
    return 0;
}
