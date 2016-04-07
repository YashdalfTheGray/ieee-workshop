# Building The Client

This a write up to walk through building an angular app that interfaces with the Particle API.

## Angular 2 Skeleton

`git` and `node` are prerequisites for this walkthrough. Start by pulling down the `angular2-ts-skeleton` repo by running `git clone https://github.com/YashdalfTheGray/angular2-ts-skeleton.git`.

You can also create a folder for this project and call it a different name. You can clone the files from the `angular2-ts-skeleton` into the folder by running `git clone https://github.com/YashdalfTheGray/angular2-ts-skeleton.git .`. Notice the `.` at the end.  

## `index.html` and `styles.css`

The `index.html` file is going to be the main entry point of the app. It is also the simplest file to create. All it contains is a listing of the CSS to be included with the app, some of the supporting code (third-party libraries), a script to load up our Angular 2 app and finally a place on the page for our Angular 2 app to be displayed.

Most of that is done for us because most of that is boilerplate. It can be copied and pasted from [here](https://gist.githubusercontent.com/YashdalfTheGray/a80085637f61daa9cd1ec07ff29917f9/raw/bf4e8e5d6710dde962b266c4a459903488be1450/index.html). Add a place for the app to be displayed by adding an `<ieee-app>Loading...</ieee-app>` tag as a child of the body.

The CSS file called `styles.css` is a collection of all the styling for our app. It should be created since we would like to customize the font for the application. We are going to change the font of the application to Google's Roboto. It's already added to our app, all we have to do is tell the browser to use it. We do this by adding the following CSS code to `styles.css`.

```css
* {
    font-family: Roboto, sans-serif;
}
```

We will be adding more styles to this file when we want to customize our table appearance.

## `app.tpl.html`  and `app.component.ts`

This will be the two parts of our main component. The top level, root component of our Angular 2 app. Let's start by importing `Component` from the `angular2/core` module and creating our first component annotation. The component annotation is accompanied by a class that is the logic driving that component. So add that next.

```javascript
import { Component } from 'angular2/core';

@Component({
    selector: 'ieee-app',
    templateUrl: 'app/app.tpl.html'
})
export class AppComponent {

}
```

The HTML part of this component will be the display that the component will have. For now, we'll just add a heading into the HTML template so that we can get started running our app. We'll add more to this later.

```html
<h1>IEEE SAC 2016 Workshop</h1>
```

## `main.ts`

This file is what the script from `index.html` will load up. We have to ask Angular 2 to bootstrap our app so that it can be displayed and the we can run the logic in our newly created component. We are also going to be talking to the Particle API so we need a way to communicate via HTTP. Angular provides us with HTTP services out of the box so we'll leverage that.

```javascript
import { bootstrap } from 'angular2/platform/browser';
import { HTTP_PROVIDERS } from 'angular2/http';

import { AppComponent } from './app.component';

bootstrap(AppComponent, [
    HTTP_PROVIDERS
]);
```

At this point, we should be able to run `npm start` and see IEEE SAC 2016 Workshop as the title in our browser. 

## `particle.service.ts` and `device.types.ts`
