//
// Created by Jonas on 10/3/19.
//

#include <chrono>
#include <thread>
#include <iostream>
#include "MainLoop.h"
#include "../rendering/Window.h"
#include "../util/Time.h"

MainLoop::MainLoop(int width, int height, const std::string &title) {
  Window::createWindow(width, height, title);
  isRunning = false;
}

void MainLoop::start() {
  if (isRunning) return;

  game->init();
  run();
}

void MainLoop::stop() {
  if (!isRunning) return;

  isRunning = false;
}

void MainLoop::run() {
  isRunning = true;

  int frames = 0;
  long frameCounter = 0;

  const double frameTime = 1 / FRAME_CAP;

  long lastTime = Time::getTime();
  double unprocessedTime = 0;

  while (isRunning) {
    bool shouldRender = false;

    long startTime = Time::getTime();
    long passedTime = startTime - lastTime;
    lastTime = startTime;

    unprocessedTime += (double) passedTime / (double) Time::SECOND;
    frameCounter += passedTime;

    while (unprocessedTime > frameTime) {
      shouldRender = true;

      unprocessedTime -= frameTime;

      if (Window::isCloseRequested()) stop();

      Time::setDelta(frameTime);

      // -- Update Game --
      game->input();
      game->update();
      // -- Update Game --

      if (frameCounter >= Time::SECOND) {
        std::cout << frames << std::endl;
        frames = 0;
        frameCounter = 0;
      }
    }

    if (shouldRender) {
      render();
      frames++;
    } else {
      std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }

  }

  cleanUp();

}

void MainLoop::render() {
  Window::clear();
  game->render();
  Window::render();
}

void MainLoop::cleanUp() {
  game->dispose();
  Window::dispose();
}
