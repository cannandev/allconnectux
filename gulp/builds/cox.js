'use strict';

var gulp = require('gulp'),
    browserSync = require('browser-sync').create(),
    plugin = require('../helpers/plugins'),
    developer = require('../helpers/developer'),
    glob = require('../builds/global'),
    tasks = require('../tasks'),
    sysMsg = require('../system/messages'),
    cox = 'cox/themes/cox/',
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
gulp.task('cox:images', tasks.imageMin(cox));

// -------------------------------------------
//  Lint CSS
// -------------------------------------------//
gulp.task('cox:csslint', tasks.lintStyles(cox));

// -------------------------------------------
//  Compile Styles
// -------------------------------------------//
// Xfinity Only
gulp.task('cox:css', tasks.compileStyles(cox));

// Global
gulp.task('cox:styles', ['cox:css', 'global:css']);

// Watch
gulp.task('cox:watch', function() {
    gulp.watch('**/*.scss', ['cox:css', 'global:css']);
});

// -------------------------------------------
//  Launch Xfinity Server
// -------------------------------------------//
gulp.task('cox:serve', function() {
    browserSync.init(developer.serveMe);
    gulp.watch('**/*.scss', ['cox:css', 'global:css']);
    gulp.watch(reloadPaths).on('change', function() {
        reload();
        plugin.notify(sysMsg.reloaded).write('');
    });
});
