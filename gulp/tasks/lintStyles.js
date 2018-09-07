'use strict';

// Lint styles for css standardization

var gulp = require('gulp'),
    plugin = require('../helpers/plugins'),
    paths = require('../helpers/paths'),
    stylelint = require('stylelint'),
    xfinity = 'xfinity/themes/xfinity/',
    reporter = require('postcss-reporter');


    module.exports = function lintStyles (dir) {
        return function(cb) {
            gulp.src((dir + paths.inputs.css))
              .pipe(plugin.postcss([
                    stylelint(),
                    reporter({ clearMessages: true })
                ]));
            cb();
        }
    };