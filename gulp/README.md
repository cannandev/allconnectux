# Gulp Modular Workflow

**Author:** Anthony Daniel, <anroosdan@gmail.com>

**Contributors:** Claire Annan, Aaron Turner

**Description**:
This workflow breaks up all dependencies into manageable units for better maintenance and development continuation.

This workflow was designed to evolve.

### Resources

**Packages**

<http://gulpjs.com/plugins/>

<https://www.npmjs.com/>

### Current Workflow supports 

- Compiling Sass
- Linting CSS
- CSS Optimization
- Image Optimization
- Browser/device testing
- Notifications

## Installation
Once you have installed gulp and npm, open Terminal to your project folder:

```cd allconnect-multisite-master/sites```

Run the following command to install required node modules. This will take a few minutes.

```npm install```

## Getting started

From the project folder, run the following the command to see available tasks:

```
gulp --tasks
```

To run a task, run the following command:

```
gulp <taskname>
```

For example, to watch for compiled changes locally, run:

```
gulp xfinity:watch
```



## Browsersync
<https://browsersync.io/docs/gulp/>

Browsersync allows you to view saved changes in any browser or device.

Edit the following files to set up your localhost server:

`gulp/helpers/developer.js`

`builds/xfinity.js`


Keep changes to these files local. *DO NOT COMMIT TO THE REPOSITORY.*

To launch a browsersync server, run:

```
gulp xfinity:serve
```



## Expanding the system

To add plugins the system run the following command

```
npm install <packagename> --save
```

This will load the plugin as a dependency in your package.json file

