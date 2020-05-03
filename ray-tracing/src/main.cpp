#include <iostream>
#include <cmath>
#include "camera.hpp"
#include "image.hpp"
#include "sphere.hpp"
#include "scene.hpp"
#include "light_point.hpp"
#include "plane.hpp"

using namespace std;

int main()
{
    // define a camera
    Camera camera;
    camera.setPosition(Vector3(0.0, -10.0, 2.0));
    camera.setLookAt(Vector3(0.0, 0.0, 0.0));
    camera.setLength(1.5);
    camera.setUp(Vector3(0.0, 0.0, 1.0));
    camera.setSize(0.5);
    camera.updateCamera();

    // define an object
    Sphere sphere1 = Sphere(Vector3(0.0, 0.0, 0.0), 1.0);
    sphere1.setBaseColor(Color(0.2, 0.5, 0.8));
    Sphere sphere2 = Sphere(Vector3(-2.5, 0.0, 0.0), 1.0);
    sphere2.setBaseColor(Color(1.0, 0.5, 0.0));
    Sphere sphere3 = Sphere(Vector3(2.5, 0.0, 0.0), 1.0);
    sphere3.setBaseColor(Color(1.0, 0.75, 0.0));

    // define a floor plane
    Plane floor(Vector3(0.0, 0.0, -1.0), Vector3(1.0, 0.0, -1.0), Vector3(0.0, 1.0, -1.0));
    floor.setBaseColor(Color(0.0, 0.5, 0.5));

    // create the scene
    Scene scene;
    scene.addCamera(camera);
    scene.addObject(&sphere1);
    scene.addObject(&sphere2);
    scene.addObject(&sphere3);
    scene.addObject(&floor);

    // define a light source
    LightPoint light1(Vector3(5.0, -5.0, 10.0), Color(1.0, 1.0, 1.0), 0.5);
    scene.addLight(&light1);
    LightPoint camLight(camera.position, Color(1.0, 1.0, 1.0), 0.125);
    scene.addLight(&camLight);
    LightPoint light2(Vector3(-5.0, -5.0, 10.0), Color(1.0, 1.0, 1.0), 0.5);
    scene.addLight(&light2);

    // create an Image
    Image img(1920, 1080);
    
    // render into the image
    scene.render(&img);
    img.toFile("rendered.bmp");

    return 0;
}