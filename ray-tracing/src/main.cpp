#include <iostream>
#include <cmath>
#include "camera.hpp"
#include "image.hpp"
#include "sphere.hpp"
#include "scene.hpp"

using namespace std;

int main()
{
    // define a camera
    Camera camera;
    camera.setPosition(Vector3(0.0, -10.0, 0.0));
    camera.setLookAt(Vector3(0.0, 0.0, 0.0));
    camera.setLength(1.5);
    camera.setUp(Vector3(0.0, 0.0, 1.0));
    camera.updateCamera();

    // define an object
    Sphere sphere = Sphere(Vector3(-0.5, 0.0, 0.0), 0.25);
    sphere.setBaseColor(Color(0.2, 0.5, 0.8));
    Sphere sphere1 = Sphere(Vector3(0.5, 0.0, 0.0), 0.25);

    // create the scene
    Scene scene;
    scene.addCamera(camera);
    scene.addObject(&sphere);
    scene.addObject(&sphere1);

    // create an Image
    Image img(1920, 1080);
    
    // render into the image
    scene.render(&img);
    img.toFile("rendered.bmp");

    return 0;
}