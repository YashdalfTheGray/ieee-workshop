# ieee-workshop-client

## Prereqs

`node` and `git` will need to be installed. This can be verified by running `node --version` and `git --version` from the command line. This should print out the versions.

Typescript and Typings will also need to be installed globally. This can be done by running `npm install --global typescript typings`. 

## Installation

If you're in the project root, use `cd` to switch to the `client` directory and then run `npm install`.

The Angular 2 client is written in Typescript which needs to be compiled down to Javascript. The Javascript then also needs to be served so that the code can be seen working. Running an `npm start` from the the `client` folder will both compile the Typescript (and watch for changes and recompile) and run a webserver locally to serve up the application.

## Other `npm` commands

There are other commands listed under the `scripts` object of the `package.json` file in this directory. The table below shows the commands and effects.

| Command          | Effect                                                             |
|------------------|--------------------------------------------------------------------|
| `npm run tsc`    | Compile all the typescript files once                              |
| `npm run tsc:w`  | Compile all the typescript files and recompile on changes          |
| `npm run server` | Start a server locally on port 3000                                |
| `npm run clean`  | Clean out the directory of any files not tracked by source control |

The `postinstall` entry under `scripts` is something that `npm` will run automatically after an `npm install`. Also, `npm run clean` will clean out the folder that the compiled Typescript goes into and also any new files that are added to the folder but not tracked by source control which in this case is git. This is a dangerous command to run when actively developing and the changes haven't been committed to git.
