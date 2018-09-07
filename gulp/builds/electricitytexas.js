'use strict';

var gulp = require('gulp'),
    browserSync = require('browser-sync').create(),
    plugin = require('../helpers/plugins'),
    developer = require('../helpers/developer'),
    glob = require('../builds/global'),
    tasks = require('../tasks'),
    sysMsg = require('../system/messages'),
    electricitytexas = 'electricitytexas/themes/electricitytexas/',
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
gulp.task('electricitytexas:images', tasks.imageMin(electricitytexas));

// -------------------------------------------
//  Lint CSS
// -------------------------------------------//
gulp.task('electricitytexas:csslint', tasks.lintStyles(electricitytexas));

// -------------------------------------------
//  Compile Styles
// -------------------------------------------//
// electricitytexas Only
gulp.task('electricitytexas:css', tasks.compileStyles(electricitytexas));

// Global
gulp.task('electricitytexas:styles', ['electricitytexas:css', 'global:css']);

// Watch
gulp.task('electricitytexas:watch', function() {
    gulp.watch('**/*.scss', ['electricitytexas:css', 'global:css']);
});

// -------------------------------------------
//  Launch electricitytexas Server
// -------------------------------------------//
gulp.task('electricitytexas:serve', function() {
    browserSync.init(developer.serveMe);
    gulp.watch('**/*.scss', ['electricitytexas:css', 'global:css']);
    gulp.watch(reloadPaths).on('change', function() {
        reload();
        plugin.notify(sysMsg.reloaded).write('');
    });
});
