#pragma once

namespace Catcher::Survivor
{
    class Scene
    {
        public:
            virtual void handleInput() { };
            virtual void fixedUpdate() { };
            virtual void lateUpdate() { };
            virtual void update() { };
            virtual void draw() { };
            virtual void drawGui() { };
    };
}
