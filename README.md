# ieee-workshop
IEEE SAC 2016 Workshop by Rockwell Automation

We are going to be building a web interface that queries light and temperature sensors for data and uses it to make decisions. This will be done using [Particle Photons](https://store.particle.io/collections/photon) acting as the data emitters and a web-based Single Page Application behaving as the decision maker and dashboard.

Experience in Javascript is not required but will help and all the code, parts list and presentation materials will be stored in this repository and will be available indefinitely. 

## Setup Instructions
There are 3 things that you will need to download and install before the workshop:
* [`git`](https://git-scm.com/downloads "Git Download") (a note on `git` for OS X later)
* [`nodejs`](https://nodejs.org/en/download/ "Node Download")
* A text editor (see below)

Please get these installed before you show up, it will make things a go a lot smoother. If you have any trouble getting them installed or questions don't hesitate to email us. We were in your shoes not too long ago, don't worry about asking questions, that's how we learn.

**NOTE** - `git` for OS X comes packaged with the Xcode command line tools. Installing Xcode from the App Store and running it should install `git` for OS X. Another way to make sure you get `git` is to run `git` from the Terminal. If `git` is not found, it will ask you to install the Xcode Command Line Tools if you're on OS X 10.11 or greater.

### What are these things?

**If you've never used these before, here's the short explanation to what they are and why we need them.**

#### [`git`](https://git-scm.com/)
`git` is the tool we will use to download the code repository we'll be using for the workshop from the web to your computer. Check out the [site](https://git-scm.com/) and try the online [tutorial](https://try.github.io/levels/1/challenges/1) if you're interested in learning more. Yes, it uses the command line; no need to be scared, it's easy once you get the hang of it. No need to do anything with `git` except install it, if you don't already know, we'll show you everything else at the workshop!

#### [nodejs](https://www.nodejs.org/)
We really are using nodejs on your machine for it's package management tool, `npm`. What is `npm`? It stands for Node Package Manager. In short, it allows us to give you a tiny file with a list of packages in it, then `npm` will read that file, run out to the web and download all of those things and install them in the code repository for our project to use. If you want to learn a little bit of node, a great resource is [nodeschool.io](www.nodeschool.io).

#### Text Editor

**We're engineers, we have great tools to make our lives easier!**

You're going to need something to write code with in the workshop. While all of the files we are working with are simply text files that you could open with notepad, it gets very difficult to open and close files if you are browsing around. There's lots of editors out there for programmers, take your pick! Here are some suggestions.
* [Atom](https://atom.io/)
* [Sublime Text 3](https://www.sublimetext.com/3)
* [Notepad++](https://notepad-plus-plus.org/)

## Tutorials

We are going to be using Angular2 and Typescript for this workshop. Think of Typescript as a superset of Javasript so all Javascript is legal Typescript. If you're interested in learning a little more about either of these subjects, we have selected some tutorials to help you get started.

* [Javascript](http://nodeschool.io/#workshoppers) - check out the `javascripting` tutorial to learn a bit about the language. You are going to need `node` and `git` installed for this so do this after getting those installed.
* [Javascript CodeCombat](https://codecombat.com/play) - a great tool to start learning programming (in general) while also casually gaming. It supports python and javascript (and a couple of other languages) syntaxes.
* [Angular2 quickstart](https://angular.io/docs/ts/latest/quickstart.html) - the Angular2 quickstart really only takes 5-10 minutes to run through and it gives an overview of what Angular2 is and how to get started writing code in it. It also gives a basic introduction to Typescript and the ES6 syntax for JavaScript.
* [Typescript](http://www.typescriptlang.org/docs/tutorial.html) - This is a Typescript quickstart tutorial. Like the Angular2 quickstart, it also doesn't take long and it gives a crash course on what Typescript is and the features.
