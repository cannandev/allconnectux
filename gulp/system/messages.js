'use strict';

module.exports = {
    success: {
        "title": "Hey bud!",
        "onLast": true,
        "wait": true,
        // "icon": path.join(__dirname, "gulp-icon.jpeg"),
        message: "I've Generated file: <%= file.relative %>"
    },
    error: {
        "title": "Uh Oh...",
        "onLast": true,
        "wait": true,
        // "icon": path.join(__dirname, "gulp-error-icon.jpg"),
        message: "Error: <%= error.message %>",
    },
    reloaded: {
        title: "Files changed",
        message: "Browser reloaded!",
        "wait": true
    }
}
