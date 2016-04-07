# ieee-workshop-talk

The Internet of Things (IoT) is starting to become more and more prevalent in daily life. There are low-power, smart devices everywhere and with the increasing affordability of such devices, IoT is only going to gain more ground. This workshop aims to introduce the core idea behind automation in the context of home automation using a web app and a Particle Photon.

## Rockwell Automation

As an industrial automation company, Rockwell has a vested interest in the proliferation of these affordable, low-power, smart devices because they can be used to access data from the shop floor of a production facility in ways that were previously impractical.

Along with these connected devices, IoT has also encouraged a larger focus on web and mobile development. We have embraced the mobile-first strategy and are working on creating data paths from connected devices across a facility to a common platform.

## Automation

Sensors collect data which is then passed to something that makes decisions based on that data and may also even pass that data along to something that knows how to display it. This is the core idea behind automation. This is true for a cookie oven in a factory and for the smart lights in houses. It all works on the same principle.

## Tech Stack

We use a Particle Photon as a data collector, the Particle HTTP REST API as the data server and Angular 2 as the controller and display. These technologies might sound arbitrary at first so let's talk about why we picked them.

### Particle Photon + Particle HTTP REST API

We picked the Particle Photon because it is a very affordable, wifi enabled microcontroller which still offers much of the same features as an Arduino. It can be programmed using a cloud IDE called Particle Build, flashed over the air and is very intuitive to work with. With the Photon, Particle has lowered the cost of entry into the world of affordable and connected devices.

The Photon sends the data that it collects to the Particle servers. This enabled Particle to wrap a well-documented and well-built HTTP API around the data coming out a Photon. Since most languages have a HTTP library, interfacing with the data being served by a Photon (or any Particle device) becomes very easy and opens up the data to a myriad of clients.

### Angular 2

Angular 2 is the successor to the well-known Javascript framework, AngularJS. Angular 2 is a fully featured MV* framework which offers utilities to publish a well-designed, fast Single Page Application which is both desktop and mobile friendly while being totally cross-platform. Rockwell has embraced AngularJS and is starting to use AngularJS in more and more of products in our catalog.

Angular 2 is in beta right now but it is seeing wide adoption so we thought that we would start with Angular 2. 
