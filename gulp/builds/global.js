'use strict';

var gulp = require('gulp'),
    helper = require('../helpers'),
    pipes = require('../pipes'),
    tasks = require('../tasks'),
    global = 'all/themes/acbrand/';

module.exports =
  gulp.task('global:css', tasks.compileStyles(global));