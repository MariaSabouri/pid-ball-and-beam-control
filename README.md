# PID Control of a Ball-and-Beam System

A control engineering project implementing a Proportional–Integral–Derivative (PID) controller to regulate the position of a ball on a one-dimensional, servo-actuated beam.

## Project Overview

The objective of this project was to control a ball's position on a beam and keep it at a desired reference point using a servo motor.

The servo adjusts the beam's inclination, causing the ball to move along the beam. The controller continuously responds to the position error to bring the ball toward the target and maintain its position despite gravitational and frictional effects.

## Control Strategy

A PID controller was implemented to regulate the ball's position.

The controller uses the difference between the desired and measured ball positions to calculate the control action applied to the servo motor.

The three PID components contribute as follows:

- **Proportional (P):** Responds to the current position error.
- **Integral (I):** Accumulates past errors to help eliminate steady-state error.
- **Derivative (D):** Responds to the rate of change of error to help improve system response.

PID control was selected as a practical, model-independent control approach that does not require an explicit mathematical model of the complete system for implementation.

## System Components

- One-dimensional ball-and-beam mechanism
- Servo motor for beam-angle adjustment
- Ball-position measurement
- PID feedback controller
- Desired position reference

## Project Objectives

- Regulate the ball position around a specified reference point.
- Use servo actuation to control the ball's motion along the beam.
- Investigate PID feedback control in the presence of gravitational and frictional effects.
- Evaluate the controller's ability to maintain the desired position.

## Project Demonstration

Watch the video demonstration of the physical system and its control behavior:

[**Watch the Ball-and-Beam PID Control Demo**](YOUR_GOOGLE_DRIVE_VIDEO_LINK)

## Technologies and Concepts

- PID Control
- Feedback Control Systems
- Servo Motor Actuation
- Position Regulation
- Control Engineering

## Key Learning Outcomes

- Practical implementation of feedback control.
- Understanding the roles of proportional, integral, and derivative actions.
- Applying PID control to a dynamic mechanical system.
- Observing the effects of gravity and friction on position regulation.

## Project Type

Practical Control Engineering Project
