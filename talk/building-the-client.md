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

These will be the two parts of our main component; the top level, root component of our Angular 2 app. Let's start by importing `Component` from the `angular2/core` module and creating our first component annotation. The component annotation is accompanied by a class that is the logic driving that component. So add that next.

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

## `device.types.ts`

Now we'll add some data interaction into the app. We'll first create a data type to store the data coming from Particle and then we'll create a service (a component without any view) to get that data for us. Add a file called `device.types.ts`. This file contains a type definition that is used to tell Typescript what kind of data we are expecting from Particle. Since it's a fair amount of typing, the contents of the file can be copied from [here](https://gist.githubusercontent.com/YashdalfTheGray/a80085637f61daa9cd1ec07ff29917f9/raw/21e1cda7784ab6c0a1b0de498f6a40fd9f5ef13f/device.types.ts).

The syntax of note in `devices.types.ts` is the `export type Device` line. This creates a new type of variable that we can use called `Device` and lists out all the properties that it can have. Look at the last property in that type definition, the one called `variables`. The `?` before `:` means that it is optional and at any point, the variables member of this type may or may not be present on an instance. Similarly, the `DeviceVariables` type has three optional members.

## `particle.service.ts`

The service we are going to add is going to live under the file `particle.service.ts`. The skeleton for this service can be copied and pasted from [here](https://gist.githubusercontent.com/YashdalfTheGray/a80085637f61daa9cd1ec07ff29917f9/raw/b5f385a0b5bdc15a9f1c26d0c3820bc5d71a3b14/particle.service.ts). The skeleton helps us out with a couple of things. First, we tell Angular that this service can be injected as a dependency into other components in the app. We also pull in `Http`, `Response`, `RequestOptions` and `Headers` from `angular2/http` and `Observable` from `../node_modules/rxjs/Rx.d.ts`. We will use these to write code to talk to our Particle API.

First, let's ask Angular to give us a reference to the `Http` object. That will happen in the class constructor. We need two pieces of data from the Particle API. A list of devices that are available to us for consuming data from and the actual data from these devices. For this we'll write two methods, `getDevices()` and `getVariable()`.

One thing to keep in mind is that the Particle API requires authorization. We use the `RequestOptions` class to customize the headers that we are attaching to the request and the `Headers` class set custom headers to our request.

The return value from our functions is `Observable<Response>`. An `Observable` is just a data stream. It can be represented by a timeline that has events happening every so often and at some point, it ends. We'll see how to get data out of an `Observable` when we start using our service.

```javascript
export class ParticleService {
    constructor(public http: Http) { }

    getDevices(): Observable<Response> {
        var reqOptions = new RequestOptions({
            headers: new Headers({
                'Authorization': 'Bearer ieee-sac-2016-workshop'
            })
        });
        return this.http.get('https://particle-proxy.herokuapp.com/api/v1/devices', reqOptions);
    }

    getVariable(deviceId: string, variableName: string): Observable<Response> {
        var reqOptions = new RequestOptions({
            headers: new Headers({
                'Authorization': 'Bearer ieee-sac-2016-workshop'
            })
        });
        return this.http.get(
            'https://particle-proxy.herokuapp.com/api/v1/devices/' + deviceId + '/' + variableName,
            reqOptions
        );
    }
}
```

## Using `ParticleService` in `AppComponent`

Let us start with importing `ParticleService` into our `AppComponent`.

## Creating a `<table>` using `ngFor`

This section is the last section required to have a fully functioning app, you should now be able to get data from the particle service and display it in a table!

## Bonus Challenges

1) Even though we have a stable app now, we need a way to get new data outside of just refreshing the page. So think about how to implement a refresh button without changing too much of the code in `AppComponent`.

Hint: Handling [click events](http://learnangular2.com/events/) with Angular 2.

2) Create an element on the page akin to an indicator. An indicator is one color (usually green) for when a some sensor value meets certain criteria and turns red when it doesn't.

Hint: Look into [`ngClass`](https://angular.io/docs/ts/latest/api/common/NgClass-directive.html).

Hint: There is a CSS property called `background-color` which takes a value like #164080. Use that with `ngClass`.
