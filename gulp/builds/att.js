'use strict';

var gulp = require('gulp'),
    browserSync = require('browser-sync').create(),
    plugin = require('../helpers/plugins'),
    developer = require('../helpers/developer'),
    glob = require('../builds/global'),
    tasks = require('../tasks'),
    sysMsg = require('../system/messages'),
    att = 'att/themes/att/',
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
gulp.task('att:images', tasks.imageMin(att));

// -------------------------------------------
//  Lint CSS
// -------------------------------------------//
gulp.task('att:csslint', tasks.lintStyles(att));

// -------------------------------------------
//  Compile Styles
// -------------------------------------------//
// att Only
gulp.task('att:css', tasks.compileStyles(att));

// Global
gulp.task('att:styles', ['att:css', 'global:css']);

// Watch
gulp.task('att:watch', function() {
    gulp.watch('**/*.scss', ['att:css', 'global:css']);
});

// -------------------------------------------
//  Launch att Server
// -------------------------------------------//
gulp.task('att:serve', function() {
    browserSync.init(developer.serveMe);
    gulp.watch('**/*.scss', ['att:css', 'global:css']);
    gulp.watch(reloadPaths).on('change', function() {
        reload();
        plugin.notify(sysMsg.reloaded).write('');
    });
});
