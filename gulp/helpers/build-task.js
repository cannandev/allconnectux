'use strict';

var gulp = require('gulp'),
    configs = require('../system/configs'),
    sysMsg = require('../system/messages'),
    plugin = require('./plugins'),
    pipe = require('../pipes'),
    browserSync = require('browser-sync').create(),
    gutil = require('gulp-util');

module.exports = taskBuilder;

/**
 * Builds a build-task.
 *
 * @param {Glob} src
 * @param {Function} pipes - returns the array of task-specific pipes
 * @param {Glob} target
 *
 * @returns {task}
 */

function taskBuilder(source, pipes, target) {
    return function(cb) {
        gulp.src(source)
            .pipe(plugin.plumber(function(error) {
              gutil.log(gutil.colors.red('Error (' + error.plugin + '): ' + error.message));
              plugin.notify.onError(sysMsg.error)(error);
              this.emit('end');
            }))
            .pipe(pipes())
            .pipe(plugin.sourcemaps.write('.'))
            .pipe(gulp.dest(target))
            .pipe(browserSync.stream());
        cb();
    };
};
