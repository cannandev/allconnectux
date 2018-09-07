' use strict';

// Optimize images

var gulp = require('gulp'),
    plugin = require('../helpers/plugins'),
    paths = require('../helpers/paths');

module.exports = function imgMin (dir) {
  return function (cb) {
    gulp.src((dir + paths.inputs.images))
      .pipe(plugin.imagemin())
      .pipe(gulp.dest(dir + paths.outputs.images))
  }
}