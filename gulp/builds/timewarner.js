'use strict';

var gulp = require('gulp'),
    browserSync = require('browser-sync').create(),
    plugin = require('../helpers/plugins'),
    developer = require('../helpers/developer'),
    glob = require('../builds/global'),
    tasks = require('../tasks'),
    sysMsg = require('../system/messages'),
    timewarner = 'timewarner/themes/timewarner/',
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
gulp.task('timewarner:images', tasks.imageMin(timewarner));

// -------------------------------------------
//  Lint CSS
// -------------------------------------------//
gulp.task('timewarner:csslint', tasks.lintStyles(timewarner));

// -------------------------------------------
//  Compile Styles
// -------------------------------------------//
// timewarner Only
gulp.task('timewarner:css', tasks.compileStyles(timewarner));

// Global
gulp.task('timewarner:styles', ['timewarner:css', 'global:css']);

// Watch
gulp.task('timewarner:watch', function() {
    gulp.watch('**/*.scss', ['timewarner:css', 'global:css']);
});

// -------------------------------------------
//  Launch timewarner Server
// -------------------------------------------//
gulp.task('timewarner:serve', function() {
    browserSync.init(developer.serveMe);
    gulp.watch('**/*.scss', ['timewarner:css', 'global:css']);
    gulp.watch(reloadPaths).on('change', function() {
        reload();
        plugin.notify(sysMsg.reloaded).write('');
    });
});
