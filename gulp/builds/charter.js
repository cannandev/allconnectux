'use strict';

var gulp = require('gulp'),
    browserSync = require('browser-sync').create(),
    plugin = require('../helpers/plugins'),
    developer = require('../helpers/developer'),
    glob = require('../builds/global'),
    tasks = require('../tasks'),
    sysMsg = require('../system/messages'),
    charter = 'charter/themes/charter/',
    reload = browserSync.reload;

var reloadPaths = [
    '**/*.css',
    '**/*.php',
    '**/*.html',
    '**/*.inc',
];

// Build Global Styles
module.exports =

// -------------------------------------------
//  Optimize Images
// -------------------------------------------//
gulp.task('charter:images', tasks.imageMin(charter));

// -------------------------------------------
//  Lint CSS
// -------------------------------------------//
gulp.task('charter:csslint', tasks.lintStyles(charter));

// -------------------------------------------
//  Compile Styles
// -------------------------------------------//
// Xfinity Only
gulp.task('charter:css', tasks.compileStyles(charter));

// Global
gulp.task('charter:styles', ['charter:css', 'global:css']);

// Watch
gulp.task('charter:watch', function() {
    gulp.watch('**/*.scss', ['charter:css', 'global:css']);
});

// -------------------------------------------
//  Launch Xfinity Server
// -------------------------------------------//
gulp.task('charter:serve', function() {
    browserSync.init(developer.serveMe);
    gulp.watch('**/*.scss', ['charter:css', 'global:css']);
    gulp.watch(reloadPaths).on('change', function() {
        reload();
        plugin.notify(sysMsg.reloaded).write('');
    });
});
