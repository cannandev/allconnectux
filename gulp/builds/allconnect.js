'use strict';

var gulp = require('gulp'),
    browserSync = require('browser-sync').create(),
    plugin = require('../helpers/plugins'),
    developer = require('../helpers/developer'),
    glob = require('../builds/global'),
    tasks = require('../tasks'),
    sysMsg = require('../system/messages'),
    allconnect = 'all/themes/allconnect/',
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
gulp.task('allconnect:images', tasks.imageMin(allconnect));

// -------------------------------------------
//  Lint CSS
// -------------------------------------------//
gulp.task('allconnect:csslint', tasks.lintStyles(allconnect));

// -------------------------------------------
//  Compile Styles
// -------------------------------------------//
// Xfinity Only
gulp.task('allconnect:css', tasks.compileStyles(allconnect));

// Global
gulp.task('allconnect:styles', ['allconnect:css', 'global:css']);

// Watch
gulp.task('allconnect:watch', function() {
    gulp.watch('**/*.scss', ['allconnect:css', 'global:css']);
});

// -------------------------------------------
//  Launch Xfinity Server
// -------------------------------------------//
gulp.task('allconnect:serve', function() {
    browserSync.init(developer.serveMe);
    gulp.watch('**/*.scss', ['allconnect:css', 'global:css']);
    gulp.watch(reloadPaths).on('change', function() {
        reload();
        plugin.notify(sysMsg.reloaded).write('');
    });
});
