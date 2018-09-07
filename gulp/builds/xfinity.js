'use strict';

var gulp = require('gulp'),
    browserSync = require('browser-sync').create(),
    plugin = require('../helpers/plugins'),
    developer = require('../helpers/developer'),
    glob = require('../builds/global'),
    tasks = require('../tasks'),
    sysMsg = require('../system/messages'),
    xfinity = 'xfinity/themes/xfinity/',
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
gulp.task('xfinity:images', tasks.imageMin(xfinity));

// -------------------------------------------
//  Lint CSS
// -------------------------------------------//
gulp.task('xfinity:csslint', tasks.lintStyles(xfinity));

// -------------------------------------------
//  Compile Styles
// -------------------------------------------//
// Xfinity Only
gulp.task('xfinity:css', tasks.compileStyles(xfinity));

// Global
gulp.task('xfinity:styles', ['xfinity:css', 'global:css']);

// Watch
gulp.task('xfinity:watch', function() {
    gulp.watch('**/*.scss', ['xfinity:css', 'global:css']);
});

// -------------------------------------------
//  Launch Xfinity Server
// -------------------------------------------//
gulp.task('xfinity:serve', function() {
    browserSync.init(developer.serveMe);
    gulp.watch('**/*.scss', ['xfinity:css', 'global:css']);
    gulp.watch(reloadPaths).on('change', function() {
        reload();
        plugin.notify(sysMsg.reloaded).write('');
    });
});
