# Building The Client

This a write up to walk through building an angular app that interfaces with the Particle API.

## Angular 2 Skeleton

`git` and `node` are prerequisites for this walkthrough. Start by pulling down the `angular2-ts-skeleton` repo by running `git clone https://github.com/YashdalfTheGray/angular2-ts-skeleton.git`.

You can also create a folder for this project and call it a different name. You can clone the files from the `angular2-ts-skeleton` into the folder by running `git clone https://github.com/YashdalfTheGray/angular2-ts-skeleton.git .`. Notice the `.` at the end.  

## `index.html` and `styles.css`

The `index.html` file is going to be the main entry point of the app. It is also the simplest file to create. All it contains is a listing of the CSS to be included with the app, some of the supporting code (third-party libraries), a script to load up our Angular 2 app and finally a place on the page for our Angular 2 app to be displayed.

Most of that is done for us because most of that is boilerplate. Add a place for the app to be displayed by adding an `<ieee-app>Loading...</ieee-app>` tag as a child of the body.

The CSS file called `styles.css` is a collection of all the styling for our app. It should be created since we would like to customize the font for the application. We are going to change the font of the application to Google's Roboto. It's already added to our app, all we have to do is tell the browser to use it. We do this by adding the following CSS code to `styles.css`.

```css
* {
    font-family: Roboto, sans-serif;
}
```

We will be adding more styles to this file when we want to customize our table appearance.

## `main.ts`



## `app.tpl.html`  and `app.component.ts`



## `particle.service.ts` and `device.types.ts`
