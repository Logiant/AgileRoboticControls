/*!
 * ninjalib.js v0.6.10
 * Thursday, May 8th, 2014, 4:14:37 PM
 */
/*
 * @license
 * Analytics Ninja - GA Tracking Library version
 * This software is made available by LICENSE ONLY.
 * Analytics Ninja LLC
 * http://www.analytics-ninja.com
 *
 * Many aspects of this tracking library come from publicly available scripts, including:
 *
 * whet.extend v0.9.7
 * Standalone port of jQuery.extend that actually works on node.js
 * https://github.com/Meettya/whet.extend
 * Copyright 2012, Dmitrii Karpich
 * Released under the MIT License
 *
 *
 * Special thanks to:
 * @author Eduardo Cereto <eduardocereto@gmail.com>
 * GAS - Google Analytics on Steroids
 *
 * Form Tracking Plugin
 * Vimeo Video Tracking Plugin
 * YouTube Video Tracking Plugin
 *
 * Copyright 2011, Cardinal Path and Direct Performance
 * Licensed under the GPLv3 license.
 *
 *
 * DownloadTracker based on code from Blast Advanced Media.
 * http://www.blastam.com/blog/index.php/2011/04/how-to-track-downloads-in-google-analytics/
 *
 * 
 * ScrollTracker by Justin Cutroni, see http://cutroni.com/blog/2012/02/21/advanced-content-tracking-with-google-analytics-part-1/  
 * Included Version by Eivind Savio, see http://www.savio.no/blogg/a/114/tracking-content-scrollers-scanners-og-readers-in-google-analytics
 *
 *
 * Rank tracker from AJ Kohn
 * http://www.blindfiveyearold.com/new-ways-to-track-keyword-rank
 */


(function(window, undefined) {
    

/*jshint unused: false */
var extend = function() {

    var _extend, _findValue, _isClass, _isOwnProp, _isPlainObj, _isPrimitiveType, _isTypeOf, _prepareClone, __slice = [].slice;

    _extend = function() {
        var args, copy, deep, name, options, target, _i, _len, _ref;
        
        deep = arguments[0];
        target = arguments[1];

        if (arguments.length >= 3) {
            args = __slice.call(arguments, 2);
        } else {
            args = [];
        }

        if (!_isClass(deep, 'Boolean')) {
            args.unshift(target);
            _ref = [deep || {},
            false]; target = _ref[0]; deep = _ref[1];
        }
        if (_isPrimitiveType(target)) {
            target = {};
        }
        for (_i = 0, _len = args.length; _i < _len; _i++) {
            options = args[_i];
            if (options !== null) {
                for (name in options) {
                    if (options.hasOwnProperty(name)) {
                        copy = options[name];
                        if ((copy !== null) && target[name] !== copy) {
                            target[name] = _findValue(deep, copy, target[name]);
                        }
                    }
                }
            }
        }
        return target;
    };



    /*
    Internal methods from now
    */
    _isClass = function(obj, str) {
        return ("[object " + str + "]") === Object.prototype.toString.call(obj);
    };

    _isOwnProp = function(obj, prop) {
        return Object.prototype.hasOwnProperty.call(obj, prop);
    };

    _isTypeOf = function(obj, str) {
        return str === typeof obj;
    };

    _isPlainObj = function(obj) {
        var key;
        if (!obj) {
            return false;
        }
        if (obj.nodeType || obj.setInterval || !_isClass(obj, 'Object')) {
            return false;
        }
        if (obj.constructor && !_isOwnProp(obj, 'constructor') && !_isOwnProp(obj.constructor.prototype, 'isPrototypeOf')) {
            return false;
        }
        //for (key in obj) {
        //    //key;
        //}
        return (key === void 0 || _isOwnProp(obj, key));
    };

    _isPrimitiveType = function(obj) {
        return !(_isTypeOf(obj, 'object') || _isTypeOf(obj, 'function'));
    };

    _prepareClone = function(copy, src) {
        if (_isClass(copy, 'Array')) {
            if (_isClass(src, 'Array')) {
                return src;
            } else {
                return [];
            }
        } else {
            if (_isPlainObj(src)) {
                return src;
            } else {
                return {};
            }
        }
    };

    _findValue = function(deep, copy, src) {
        var clone;
        if (deep && (_isClass(copy, 'Array') || _isPlainObj(copy))) {
            clone = _prepareClone(copy, src);
            return _extend(deep, clone, copy);
        } else {
            return copy;
        }
    };

    
    //Call it
    return _extend.apply(this,arguments);  

},

/* GAS function for listening for events */
_addEventListener = function (obj, evt, ofnc, bubble) {
    var fnc = function (event) {
        if (!event || !event.target) {
            event = window.event;
            event.target = event.srcElement;
        }
        return ofnc.call(obj, event);
    };
    // W3C model
    if (obj.addEventListener) {
        obj.addEventListener(evt, fnc, !!bubble);
        return true;
    }
    // M$ft model
    else if (obj.attachEvent) {
        return obj.attachEvent('on' + evt, fnc);
    }
    // Browser doesn't support W3C or M$ft model. Time to go old school
    else {
        evt = 'on' + evt;
        if (typeof obj[evt] === 'function') {
            // Object already has a function on traditional
            // Let's wrap it with our own function inside another function
            fnc = (function (f1, f2) {
                return function () {
                    f1.apply(this, arguments);
                    f2.apply(this, arguments);
                };
            }(obj[evt], fnc));
        }
        obj[evt] = fnc;
        return true;
    }
},


_DOMReady = function (callback) {
    var scp = this;
    function cb() {
        if (cb.done) return;
        cb.done = true;
        callback.apply(scp, arguments);
    }
    if (/^(interactive|complete)/.test(document.readyState)){
        return cb();
    }
    _addEventListener(document, 'DOMContentLoaded', cb, false);
    _addEventListener(window, 'load', cb, false);
},

//Simple debugger which outputs only when debugging level is set and console.log exists
debug = (function(){
    /*global console:true */
    
    var _level = false;
    
    function setLevel(level) {
        _level = level;
    }
    
    function log(message,explicit_level) {

        if (explicit_level || _level) {

            if (typeof(console) !== 'undefined' && typeof(console.log) !== 'undefined') {
                var msg_to_log;
                if (typeof(message) == 'object') {
                    msg_to_log = message.join(" | ");
                } else {
                    msg_to_log = message;
                }
                console.log(msg_to_log);
            }
            
        }
    }
    
    return {
        setLevel: setLevel,
        log: log
    };
    
}());

/* jshint asi:true, lastsemic:true,evil:true */
/* global JSON:true */
if (typeof JSON !== "object") {
    JSON = {}
}(function() {
    function f(n) {
        return n < 10 ? "0" + n : n
    }
    if (typeof Date.prototype.toJSON !== "function") {
        Date.prototype.toJSON = function(key) {
            return isFinite(this.valueOf()) ? this.getUTCFullYear() + "-" + f(this.getUTCMonth() + 1) + "-" + f(this.getUTCDate()) + "T" + f(this.getUTCHours()) + ":" + f(this.getUTCMinutes()) + ":" + f(this.getUTCSeconds()) + "Z" : null
        };
        String.prototype.toJSON = Number.prototype.toJSON = Boolean.prototype.toJSON = function(key) {
            return this.valueOf()
        }
    }
    var cx = /[\u0000\u00ad\u0600-\u0604\u070f\u17b4\u17b5\u200c-\u200f\u2028-\u202f\u2060-\u206f\ufeff\ufff0-\uffff]/g,
        escapable = /[\\\"\x00-\x1f\x7f-\x9f\u00ad\u0600-\u0604\u070f\u17b4\u17b5\u200c-\u200f\u2028-\u202f\u2060-\u206f\ufeff\ufff0-\uffff]/g,
        gap, indent, meta = {
            "\b": "\\b",
            "\t": "\\t",
            "\n": "\\n",
            "\f": "\\f",
            "\r": "\\r",
            '"': '\\"',
            "\\": "\\\\"
        },
        rep;

    function quote(string) {
        escapable.lastIndex = 0;
        return escapable.test(string) ? '"' + string.replace(escapable, function(a) {
            var c = meta[a];
            return typeof c === "string" ? c : "\\u" + ("0000" + a.charCodeAt(0).toString(16)).slice(-4)
        }) + '"' : '"' + string + '"'
    }
    function str(key, holder) {
        var i, k, v, length, mind = gap,
            partial, value = holder[key];
        if (value && typeof value === "object" && typeof value.toJSON === "function") {
            value = value.toJSON(key)
        }
        if (typeof rep === "function") {
            value = rep.call(holder, key, value)
        }
        switch (typeof value) {
        case "string":
            return quote(value);
        case "number":
            return isFinite(value) ? String(value) : "null";
        case "boolean":
        case "null":
            return String(value);
        case "object":
            if (!value) {
                return "null"
            }
            gap += indent;
            partial = [];
            if (Object.prototype.toString.apply(value) === "[object Array]") {
                length = value.length;
                for (i = 0; i < length; i += 1) {
                    partial[i] = str(i, value) || "null"
                }
                v = partial.length === 0 ? "[]" : gap ? "[\n" + gap + partial.join(",\n" + gap) + "\n" + mind + "]" : "[" + partial.join(",") + "]";
                gap = mind;
                return v
            }
            if (rep && typeof rep === "object") {
                length = rep.length;
                for (i = 0; i < length; i += 1) {
                    if (typeof rep[i] === "string") {
                        k = rep[i];
                        v = str(k, value);
                        if (v) {
                            partial.push(quote(k) + (gap ? ": " : ":") + v)
                        }
                    }
                }
            } else {
                for (k in value) {
                    if (Object.prototype.hasOwnProperty.call(value, k)) {
                        v = str(k, value);
                        if (v) {
                            partial.push(quote(k) + (gap ? ": " : ":") + v)
                        }
                    }
                }
            }
            v = partial.length === 0 ? "{}" : gap ? "{\n" + gap + partial.join(",\n" + gap) + "\n" + mind + "}" : "{" + partial.join(",") + "}";
            gap = mind;
            return v
        }
    }
    if (typeof JSON.stringify !== "function") {
        JSON.stringify = function(value, replacer, space) {
            var i;
            gap = "";
            indent = "";
            if (typeof space === "number") {
                for (i = 0; i < space; i += 1) {
                    indent += " "
                }
            } else {
                if (typeof space === "string") {
                    indent = space
                }
            }
            rep = replacer;
            if (replacer && typeof replacer !== "function" && (typeof replacer !== "object" || typeof replacer.length !== "number")) {
                throw new Error("JSON.stringify")
            }
            return str("", {
                "": value
            })
        }
    }
    if (typeof JSON.parse !== "function") {
        JSON.parse = function(text, reviver) {
            var j;

            function walk(holder, key) {
                var k, v, value = holder[key];
                if (value && typeof value === "object") {
                    for (k in value) {
                        if (Object.prototype.hasOwnProperty.call(value, k)) {
                            v = walk(value, k);
                            if (v !== undefined) {
                                value[k] = v
                            } else {
                                delete value[k]
                            }
                        }
                    }
                }
                return reviver.call(holder, key, value)
            }
            text = String(text);
            cx.lastIndex = 0;
            if (cx.test(text)) {
                text = text.replace(cx, function(a) {
                    return "\\u" + ("0000" + a.charCodeAt(0).toString(16)).slice(-4)
                })
            }
            if (/^[\],:{}\s]*$/.test(text.replace(/\\(?:["\\\/bfnrt]|u[0-9a-fA-F]{4})/g, "@").replace(/"[^"\\\n\r]*"|true|false|null|-?\d+(?:\.\d*)?(?:[eE][+\-]?\d+)?/g, "]").replace(/(?:^|:|,)(?:\s*\[)+/g, ""))) {
                j = eval("(" + text + ")");
                return typeof reviver === "function" ? walk({
                    "": j
                }, "") : j
            }
            throw new SyntaxError("JSON.parse")
        }
    }
}());

/*!
 * ninjalib core object
 **/

var $;
var NINJALIB = function(){

    //Core module options. Can be overriden with arguments passed at runtime
    var options, modules, engines,
        _default_options = {
            debug: 0,
            engines: [],
            delay: {
                cookie_name: '__umtn',
                //false for default, explicit value to set
                cookie_domain: false,
                page_value: document.location.pathname + document.location.search
            }
        };


    /* Main initialization function for ninjalib
     *
     * Sets up the options object
     * initializes engines and modules
     * executes delayed commands stored in cookies
     */
    
    function init(passed_options){
        
        options = extend({},_default_options,passed_options);
        
        debug.setLevel(options.debug);

        debug.log('Ninjalib Init',options);
        
        if(!$){
            if (typeof(jQuery) !== undefined) {
                setJquery(jQuery);
            } else {
                debug.warn('No jQuery found,necessary for ninjalib');
            }
        }

        /* Initialize engines */
        for(var i = 0; i < options.engines.length; i++){
            this.engine_factory.createEngine(options.engines[i]);
        }
        engines = this.engine_factory.getEngines();

        
        /* Initialize all models that have been registered, passing each one
         * its relevant config options that we got at runtime  */
        this.modules = this.module_factory.getModules();
        for(i in this.modules){
            if (this.modules.hasOwnProperty(i)) {
                var module = this.modules[i];
                module.init(options[module.name]);
            }
            
        }
        
        executeDelayedCommands();
        
    }
    
    //The central function for processing library hits
    //loops through all arguments passed, each one is a
    //separate command to push to the engines
    function hit(){
        
        //multiple command arrays might be sent in the same push;
        //loop through them
        for(var i = 0; i < arguments.length; i++){
            
            var command = arguments[i];
            
            //if the last element of the command array is an object, it may be
            //a extensible configuration object telling us how to handle this
            //command
            if (command.length && typeof(command[command.length - 1]) == 'object') {
                
                var command_options = command[command.length - 1];
                
                //delay this command until next page load
                if (command_options['delayed']) {
                    delayCommand(command);
                    continue;
                }
                
            }
            
            //send the command to each registered engine
            for(var j = 0; j < engines.length; j++){
                engines[j].run(command);
            }
            
        }

    }
    
    //Store this command in a cookie for firing on the next page
    function delayCommand(command_to_delay) {

        //remove delayed option before saving
        delete command_to_delay[command_to_delay.length -1 ]['delayed'];
        
        //store the page value of the current page
        command_to_delay[command_to_delay.length -1]['page_value'] = options.delay.page_value;
        
        //store the hostname of the current page
        command_to_delay[command_to_delay.length -1]['hostname'] = document.location.hostname;

        //add this command to the list
        var commands = readDelayedCommands();
        commands.push(command_to_delay);
        writeDelayedCommands(commands);
        
    }

    //retreive the array of delayed commands from the cookie
    //returns empty array if no cookie exists
    function readDelayedCommands() {
        var cookie_match = document.cookie.match(new RegExp(options.delay.cookie_name+"=(.*?)(; |$)"));
        if (cookie_match) {
            return JSON.parse(cookie_match[1]);
        } else {
            return [];
        }
    }
    
    //writes an array of delay commands to the cookie; passing false will delete the cookie
    function writeDelayedCommands(commands) {
        
        var cookie_domain = options.delay.cookie_domain || document.location.hostname;
        
        if (!commands || (typeof(commands) === 'object' && commands.length === 0)) {
            document.cookie = options.delay.cookie_name +'=; expires=Thu, 01 Jan 1970 00:00:01 GMT;'+ ';domain=' + cookie_domain + ';';
        } else {
            document.cookie = options.delay.cookie_name +"="+ JSON.stringify(commands) + ';domain=' + cookie_domain + ';';
        }
    }
    
    //execute all delayed commands stored from the last page.
    function executeDelayedCommands() {
        var commands = readDelayedCommands();
        for (var i = 0; i < commands.length; i++) {
            
            var command = commands[i];
            var page_value = command[command.length - 1]['page_value'];
            var hostname  = command[command.length - 1]['hostname'];
            
            hit(['_setPageName',page_value]);
            if (hostname != document.location.hostname) {
                hit(['_setHostname',hostname]);
            }
            
            hit(command);
            
            hit(['_setPageName',options.delay.page_value]);
            if (hostname != document.location.hostname) {
                hit(['_setHostname',document.location.hostname]);
            }
            
        }
        //delete delayed cookie
        writeDelayedCommands(false);
    }
    

    
    //a helper function for setting an internal reference to jquery, in case of conflict
    function setJquery(j) {
        $ = j;
    }
    
    function getModule(name) {
        return modules[name];
    }
    
    return {
        init: init,
        hit: hit,
        setJquery: setJquery,
        getModule: getModule
    };

};


//invoke the code
var _ninja;
window._ninja = _ninja = new NINJALIB();


//skeleton class for AN modules
function AN_Module( base_config ){

    //Base options for every module
    var skeleton_config = {
        active: true,
        run: function(){}
    };

    //Extend the skeleton config with the module's base configuration options
    var config = extend({},skeleton_config,base_config);

    if(!config.name){
        throw 'Module has no name defined!';
    }
    
    //Get the module's name
    var name = config.name;
    
    //The main init function for the module, which runs when the library is run
    function init(passed_config){

        //when config value is false, don't run
        if (typeof(passed_config) !== 'undefined' && !passed_config) {
            return;
        }
        
        //Extend the module's base configuration options with runtime options passed by the user
        config = extend({},config,passed_config);
        
        //Run the modules unless it's been explicitly disabled by active:false in config options
        if(config.active){
            config.run();    
        } 
        
    }
    
    return {
        init: init,
        name: name,
        config: config
    };
    
}


//factory object for instantiating and registering AN modules
_ninja.module_factory = (function(){
    
    var module_list = {};

    return {
    
        //Pretty simple, all we do is instantiate the module and register it with the library
        createModule: function( options ){
            
            var module = new AN_Module(options);
            
            //register the new module by putting it in the modules object
            module_list[options.name] = module;
            
        },
        
        getModules: function(){
            return module_list;
        }
        
    };
    
})();



/* Form Tracking Module adapted to work with ninjalib */

_ninja.module_factory.createModule({

    name: 'forms',	
    category: 'Form Tracking',
	change_tags: ['input', 'select', 'textarea', 'hidden'],
	submit_tags: ['form'],
    run: function(){
	
		var self = this,
		parent = _ninja,
	

		getFormName = function(el) {
			while (el && el.nodeName !== 'HTML') {
				if (el.nodeName === 'FORM') {break; }
				el = el.parentNode;
			}
			if (el.nodeName === 'FORM') {
				return el.getAttribute('name') || el.getAttribute('id') || 'none';
			}
			return 'none';
		},
	
		_trackForms = function () {
			
			if (!this._formTracked) {
				this._formTracked = true;
			} else {
				//Oops double tracking detected.
				return;
			}

			var elements = [];
			var i, j;
			
			var trackField = function (e) {
			// Make sure required attrs are defined or fallback to default
                var el = e.target,
                    el_name = el.name || el.id || el.type || el.nodeName,
                    form_name = getFormName(el),
                    action = 'form (' + form_name + ')',
                    label = el_name + ' (' + e.type + ')';					
				parent.hit(['_trackEvent', self.category, action, label]);
			};		

			for (i = 0; i < self.change_tags.length; i++) {
				elements = document.getElementsByTagName(self.change_tags[i]);
	
				for (j = 0; j < elements.length; j++) {
					_addEventListener(elements[j],'change',trackField);
				}
			}
			
			for (i = 0; i < self.submit_tags.length; i++) {
				elements = document.getElementsByTagName(self.submit_tags[i]);
				for (j = 0; j < elements.length; j++) {
					_addEventListener(elements[j],'submit',trackField);
				}
			}	

		};

		//Wait for document ready event, and run the tracking code
		_DOMReady(_trackForms);
	
    }

});



_ninja.module_factory.createModule({

    name: 'links',

    local_domains: [],

    //which event to track. You probably want 'click' or 'mousedown'
    track_event: 'mousedown',

    //base list of filetypes to include in the download tracking
    filetypes: ['zip', 'exe', 'pdf', 'doc*', 'xls*', 'ppt*', 'mp3', 'rtf', 'xml', 'txt', 'dot', 'rss', 'jpe?g', 'png', 'gif', 'csv', 'vcf'],

    //filetypes to exclude even if they appear in the filetypes array
    filetypes_exclude: [],

    //filetypes to add to the filetypes array
    filetypes_include: [],

    external_link_event: true,
    external_link_callback: function() {},

    download_link_event: true,
    download_link_callback: function() {},

    mailto_link_event: true,
    mailto_link_callback: function() {},


    run: function() {

        var self = this,
            parent = _ninja;

        self.filetypes = self.filetypes.concat(self.filetypes_include);

        var _trackLinks = function() {

            var filetype_regex = new RegExp("\\.(" + self.filetypes.join("|") + ")$", "i");
            var filetype_exclusion_regex = new RegExp("\\.(" + self.filetypes_exclude.join("|") + ")$", "i");

            var itunes_link = /^itpc\:/i;

            _addEventListener(document, self.track_event, function(e) {

                var link = e.target;
                while (link.nodeName != 'A') {
                    if (link.parentNode) {
                        link = link.parentNode;
                    } else {
                        return;
                    }
                }

                var href = link.href; //get the full, compute

                //External Links
                if (href && (href.match(/^https?\:/i)) && (!href.match(document.domain))) {

                    var link_matches = href.match(/^https?\:\/\/([^\/?#]+)(?:[\/?#]|$)/i);
                    var link_domain;
                    if (link_matches) {
                        link_domain = link_matches[1];
                    }

                    //if its on another one of our domains, send over our session 
                    if (link_domain && $.inArray(link_domain, self.local_domains) > -1) {

                        //TODO
                        link.local = true;


                        //otherwise trigger an external-link event
                    } else {

                        var matches = href.match(/^https?\:\/\/([^\/?#]+)(?:[\/?#]|$)/i);
                        var domain = matches && matches[1];
                        if (self.external_link_event) {
                            parent.hit(['_trackEvent', 'External Link', domain, href, null, true]);
                        }
                        self.external_link_callback(link);

                    }

                    //Mailto
                } else if (href && href.match(/^mailto\:/i)) {

                    var mailLink = href.replace(/^mailto\:/i, '');

                    if (self.mailto_link_event) {
                        // Let's check that it's a real email link
                        if (mailLink.match(/^([a-zA-Z0-9_\.\-])+\@(([a-zA-Z0-9\-])+\.)+([a-zA-Z0-9]{2,4})+(\?.*)?$/)) {
                            parent.hit(['_trackEvent', 'Email', 'Click', mailLink]);
                        }
                    }
                    self.mailto_link_callback(link);

                }

                //Downloads
                if (href && href.match(filetype_regex) && !(href.match(filetype_exclusion_regex))) {

                    var extension = (/[.]/.exec(href)) ? (/[^.]+$/.exec(href))[0] : undefined;
                    var filePath = href.replace(/^.*\/\/[^\/]*/, '');

                    if (href.match(itunes_link)) {
                        extension = 'itunes';
                    }

                    if (self.download_link_event) {
                        parent.hit(['_trackEvent', 'Download', extension, filePath]);
                    }
                    self.download_link_callback(link);
                }
            });
        };

        _DOMReady(_trackLinks);

    }

});

/* Dummy module for triggering a pageview */

_ninja.module_factory.createModule({

    name: 'pageview',
    active: false,
    run: function(){
        
        var parent = _ninja;
        
        parent.hit(['_trackPageview']);

    }
 
});


_ninja.module_factory.createModule({ 

    name: 'scroll',

    //how to track scrolling. Valid values as follows:
    // false: don't track scrolling on this page
    // string: A jQuery selector for finding the target.
    // jquery object: The actual jQuery object to track
    // array: a 2 element array, [content_top, content_bottom],
    //   which gives an area to track defined by y-location from top
    //   of the page
    // function: a callback function which returns one of the 3 previous
    //   options    
    target: '#content',
    
    allowed: true, //send the Allowed event
    allowed_callback: function(){},
    
    started: true, // send the started event
    started_callback: function(){},
    
    bottom: true, //send the bottom event on hitting absolute page bottom
    bottom_callback: function(){},
    
    reader_type: true, //Whether to send events for reader type scanner/reader
    reader_type_callback: function(){ }, //call back when reader type event is sent

    content_bottom: false, //send event on hitting content bottom. This happens at same time as
                           //reader_type, so this is set to false by default
    content_bottom_callback: function(){}, //callback when bottom of content area is reached
    
    run: function(){

        var self = this;
        var parent = _ninja;

        var readerTime = 30; // Seconds after scroll to bottom of content before visitor is classified as "Reader"
        var readerLocation = 150; // # px before tracking a reader
        var callBackTime = 100; // Default time delay before checking location
        
        // Set some flags for tracking & execution
        var timer = 0;

        var scroller = false;
        var endContent = false;
        var didComplete = false;
        
        // Set some time variables to calculate reading time etc.
        var pageTimeLoad = 0,
            scrollTimeStart = 0,
            timeToScroll = 0,
            contentTime = 0,
            endTime = 0,
            content_top_px = null,
            content_bottom_px = null,
            content_height = 0,
            


        _getTargetDimensions = function(_target){

            var ret;

            //if we got a callback, call it to return the value
            if(typeof _target == 'function'){
                ret = _getTargetDimensions(_target());

            //if we got a 2-element array with [top,bottom]
            } else if ($.isArray(_target) && _target.length == 2) {
                ret = _target;

            //if we got a jquery object, get the top and bottom
            } else if (_target.jquery) {            
                ret = [_target.offset().top,_target.offset().top + _target.innerHeight()];                
                
            //if we got a jquery selector, get the top and bottom
            } else if (typeof(_target) == 'string' && $(_target).length) {
                var $t = $(_target).eq(0);
                ret = [$t.offset().top,$t.offset().top + $t.innerHeight()];

            } else {
                ret = false;
            }

            return ret;
    
        },
            
        _trackScroll = function(){

            pageTimeLoad = new Date().getTime();

            //set up the dimensions for the element / screen area we're going to track
            var target_dimensions = _getTargetDimensions(self.target);

            if(!target_dimensions){
                return;
            }
            content_top_px = target_dimensions[0];
            content_bottom_px = target_dimensions[1];
            content_height = content_bottom_px - content_top_px;

            // Check if content has to be scrolled
            if ($(window).height() < content_bottom_px) {
                
                if(self.allowed){
                    parent.hit(['_trackEvent', 'Page Scroll', 'Page Scroll: Allowed', window.location.pathname, content_height, true]);
                    if(typeof self.allowed_callback == 'function'){
                        self.allowed_callback(content_height);
                    }                                                            
                }
            }

            // Track the scrolling and track location
            $(window).scroll(function() {
                if (timer) {
                    clearTimeout(timer);
                }
                // Use a buffer so we don't call trackLocation too often.
                timer = setTimeout(trackLocation, callBackTime);
            });                    
            
        },
        
        // Check the location and track user
        trackLocation = function() {
            
            var window_bottom = $(window).height() + $(window).scrollTop();
            var document_height = $(document).height();
            
            // If user has scrolled beyond threshold send an event
            if (window_bottom > readerLocation && !scroller) {
                scroller = true;
                scrollTimeStart = new Date().getTime();
                if (pageTimeLoad > 0) {
                    timeToScroll = Math.round((scrollTimeStart - pageTimeLoad) / 1000);
                } else {
                    timeToScroll = "";
                }
                
                // Article scroll started
                if(self.started){
                    parent.hit(['_trackEvent', 'Page Scroll', 'Page Scroll: Started', window.location.pathname, timeToScroll, true]);
                }
                if(typeof self.started_callback == 'function'){
                    self.started_callback(timeToScroll);
                }            
                
            }
            
            // If user has hit the bottom of the content send an event
            if (window_bottom >= content_bottom_px && !endContent) {
                timeToScroll = new Date().getTime();
                contentTime = Math.round((timeToScroll - scrollTimeStart) / 1000);
                var reader_type_label, reader_type_interactive;
                if(self.reader_type){
                    if (contentTime < readerTime) {
                        reader_type_label = 'Content Scanner';
                        reader_type_interactive = true;
                    } else {
                        reader_type_label = 'Content Reader';
                        reader_type_interactive = false;                        
                    }
                        
                    parent.hit(['_trackEvent', 'Page Scroll', 'Page Scroll: ' + reader_type_label, window.location.pathname, contentTime, reader_type_interactive]);
                    if(typeof self.reader_type_callback == 'function'){
                        self.reader_type_callback(reader_type_label,contentTime);
                    }
                }
                
                if(self.content_bottom){
                    parent.hit(['_trackEvent', 'Page Scroll', 'Page Scroll: Content Bottom', window.location.pathname, null, true]);
                }
                if(typeof self.content_bottom_callback == 'function'){
                    self.content_bottom_callback();
                }        
                
                endContent = true;
            }
            
            // If user has hit the bottom send an event
            if (window_bottom == document_height && !didComplete) {
                endTime = new Date().getTime();
                var totalTime = Math.round((endTime - scrollTimeStart) / 1000);
                if(self.bottom){
                    parent.hit(['_trackEvent', 'Page Scroll', 'Page Scroll: Page Bottom', window.location.pathname, totalTime, true]);
                }
                if(typeof self.bottom_callback == 'function'){
                    self.bottom_callback(totalTime);
                }                                                        
                didComplete = true;
            }
        };
            
        _DOMReady(_trackScroll);
        
    }
    
});


/* Rank tracking for search engines */	
_ninja.module_factory.createModule({

    name: 'searchrank',	
    run: function(){

        if (document.referrer.match(/google\.([a-zA-Z]{2,5})/gi) && document.referrer.match(/cd/gi)) {
            var myString = document.referrer;
            var r        = myString.match(/cd=(.*?)&/);
            var rank     = parseInt(r[1],10);
            var kw       = myString.match(/q=(.*?)&/);
			var keyWord;
            
            if (kw[1].length > 0) {
              keyWord  = decodeURI(kw[1]);
            } else {
              keyWord = "(not provided)";
            }
          
            var p = document.location.pathname;
            _ninja.hit(['_trackEvent', 'RankTracker', keyWord, p, rank, true]);
        }
    }        

});




/* track social */
/*global FB */
_ninja.module_factory.createModule({ 
    
    name: 'social',
    facebook: true,
    twitter: true,
    linkedin: true,
    linkedin_callback_name: 'linkedin_share',
    run: function(){
    
        var self = this;
        var parent = _ninja;
        

        var initFacebook = function(){

            var oldCB = window.fbAsyncInit;
            window.fbAsyncInit = function(){
                if(typeof oldCB === 'function'){
                    oldCB();
                }   

                FB.init({
                    xfbml: true
                });
            
                FB.Event.subscribe('edge.create', function (targetUrl){
                    parent.hit(['_trackSocial','facebook', 'like', targetUrl]);
                });
                FB.Event.subscribe('edge.remove', function(targetUrl) {
                    parent.hit(['_trackSocial', 'facebook', 'unlike', targetUrl]);
                });
                FB.Event.subscribe('message.send', function(targetUrl) {
                    parent.hit(['_trackSocial', 'facebook', 'send', targetUrl]);
                });                        
            };
        
                
             //Load the SDK's source Asynchronously
            (function(d)
            {
                var js, id = 'facebook-jssdk', ref = d.getElementsByTagName('script')[0];
                if (d.getElementById(id)) {return;}
                js = d.createElement('script'); js.id = id; js.async = true;
                js.src = "//connect.facebook.net/en_US/all.js?a=b";
                ref.parentNode.insertBefore(js, ref);
            }(document));        
        };
    
        var initTwitter = function(){
    
            function trackTwitter(intent_event) {
                if (intent_event) {
                    var opt_pagePath;
                    if (intent_event.target && intent_event.target.nodeName == 'IFRAME') {
                        opt_pagePath = extractParamFromUri(intent_event.target.src, 'url');
                    }
                    parent.hit(['_trackSocial', 'twitter', 'tweet', opt_pagePath]);
                }
            }
            
            function extractParamFromUri(uri, paramName) {
                if (!uri) {
                    return;
                }
                var regex = new RegExp('[\\?&#]' + paramName + '=([^&#]*)');
                var params = regex.exec(uri);
                if (params !== null) {
                    return decodeURIComponent(params[1]);
                }
                return;
            }        
    
            window.twttr = (function (d,s,id) {
                var t, js, fjs = d.getElementsByTagName(s)[0];
                if (!d.getElementById(id)){
                    js=d.createElement(s); js.id=id; js.src="//platform.twitter.com/widgets.js"; fjs.parentNode.insertBefore(js, fjs);
                } 
                return window.twttr || (t = { _e: [], ready: function(f){ t._e.push(f); } });
               }(document, "script", "twitter-wjs"));
            
            //Wrap event bindings - Wait for async js to load
            window.twttr.ready(function () {
                window.twttr.events.bind('tweet', trackTwitter);
            });
        };
        
        
        var initLinkedIn = function(){
            window[self.linkedin_callback_name] = function(targetUrl){
                parent.hit(['_trackSocial', 'linkedin', 'share', targetUrl]);
            };
        };
        
        _DOMReady(function(){
            if(self.facebook){
                initFacebook();
            } 
            if(self.twitter){
                initTwitter();                
            }
            if (self.linkedin) {
                initLinkedIn();
            }
            
        });
    }
    
});

/* track JW Player videos */

/*global jwplayer */
_ninja.module_factory.createModule({

    name: 'video-jwplayer',

    //the event category to be sent
    category: 'video',

    action_play: 'play',
    action_pause: 'pause',
    action_progress: 'progress %{{pct}}',
    action_finish: 'finish',

    //Try to automatically detect jwplayer objects on load.
    auto: true,

    //A list of player IDs to explicitly track.
    player_ids: [],

    //At which percentages to send progress events.
    progress_markers: [25, 50, 75, 90],
    //progress_markers: false,

    //How many equally-spaced markers to divide the playback into.
    //This is mutually exclusive with progess_markers, and takes
    //effect only when progress markers is false or empty
    progress_divisions: 5,

    //event_callback: function(playlist_item,event_type){ },
    event_callback: false,


    run: function() {

        var i, self = this,
            _tracked_players = [],

            _trackJWPlayers = function() {

                if (self.auto) {

                    var objects = document.getElementsByTagName('object');
                    for (i = 0; i < objects.length; i++) {
                        if (objects[i].id && jwplayer && jwplayer(objects[i].id).getState() !== 'undefined') {
                            _trackPlayer(objects[i].id);
                        }
                    }

                }

                for (i = 0; i < self.player_ids.length; i++) {
                    _trackPlayer(self.player_ids[i]);
                }

            },

            _trackPlayer = function(id) {

                //don't double-track
                if (_tracked_players[id]) {
                    return;
                }

                _tracked_players[id] = new JwTracker(id);
            },

            JwTracker = function(id) {

                var api = jwplayer(id),

                    _playing_item = null,
                    _progress_markers = null,

                    getLabel = function() {
                        var p = getPlaylistItem();
                        if (p) {
                            return p.file || p.sources[p.index].file;
                        } else {
                            return null;
                        }
                    },

                    setPlaylistItem = function(p) {
                        _playing_item = p;
                    },

                    getPlaylistItem = function() {
                        return _playing_item;
                    },

                    generateProgressMarkers = function() {
                        if (self.progress_markers) {
                            _progress_markers = {};
                            for (i = 0; i < self.progress_markers.length; i++) {
                                _progress_markers[self.progress_markers[i]] = false;
                            }
                        } else {
                            _progress_markers = {};
                            var divisor = 100 / self.progress_divisions;
                            for (i = 0; i < 100; i++) {
                                var progress_point = divisor * Math.floor(i / divisor);
                                _progress_markers[progress_point] = false;
                            }
                        }
                    },

                    //on a progress update, figure out whether to fire
                    //an event
                    checkProgress = function(pct) {

                        var greatest_marker = 0;

                        //find the nearest marker for our progress
                        for (var j in _progress_markers) {
                            if (pct >= j && j > greatest_marker) {
                                greatest_marker = j;
                            }
                        }


                        if (greatest_marker && !_progress_markers[greatest_marker]) {
                            _progress_markers[greatest_marker] = true;
                            doProgress(greatest_marker);
                        }

                    },

                    doProgress = function(progress) {
                        sendEvent(self.action_progress.replace('{{pct}}', progress));
                    },

                    sendEvent = function(action) {
                        var _category = self.category,
                            _action = action,
                            _label = getLabel();
                        if (typeof self.event_callback == 'function') {
                            var callback_result = self.event_callback(self.category, action, getLabel(), api.getPlaylistItem());
                            if (callback_result) {
                                if (typeof callback_result == 'object') {
                                    _category = callback_result[0];
                                    _action = callback_result[1];
                                    _label = callback_result[2];
                                }
                            } else {
                                return;
                            }
                        }
                        _ninja.hit(['_trackEvent', _category, _action, _label]);
                    };


                if (!api) {
                    return;
                }

                generateProgressMarkers();

                api.onPlay(function() {
                    setPlaylistItem(api.getPlaylistItem());
                    sendEvent(self.action_play);
                });

                api.onPause(function() {
                    sendEvent(self.action_pause);
                });

                api.onComplete(function() {
                    sendEvent(self.action_finish);
                });

                api.onTime(function(e) {
                    var pct = Math.floor(100 * e.position / e.duration);
                    checkProgress(pct);
                });

            };

        _ninja.jwplayer = {
            "trackJWPlayers": _trackJWPlayers,
            "trackJWPlayer": _trackPlayer
        };

        _DOMReady(_trackJWPlayers);

    }

});

/* track vimeo events */
_ninja.module_factory.createModule({

    name: 'video-vimeo',
    category: 'video',
    action_play: 'play',
    action_pause: 'pause',
    action_progress: 'progress %{{pct}}',
    action_finish: 'finish',
    action_seek: 'seek',
    
    percentages: [25, 50, 75, 90],
    force: true,    
    run: function(){

        var self = this;
        var parent = _ninja;
    
    
        var _vimeoTimeTriggers = [];
        var _vimeoPoolMaps = {};
        
        /**
         * Cached urls for vimeo players on the page.
         *
         * @type {object}
         */
        var _vimeo_urls = {};
        
        function _vimeoPool(data) {
            if (!_vimeoPoolMaps[data.player_id]) {
                _vimeoPoolMaps[data.player_id] = {};
                _vimeoPoolMaps[data.player_id].timeTriggers = Array.prototype.slice.call(
                    _vimeoTimeTriggers
                );
            }
            if (_vimeoPoolMaps[data.player_id].timeTriggers.length > 0) {
                if (data.data.percent * 100 >=
                    _vimeoPoolMaps[data.player_id].timeTriggers[0])
                {
                    var action = _vimeoPoolMaps[data.player_id].timeTriggers.shift();
                    parent.hit([
                        '_trackEvent',
                        self.category,
                        self.action_progress.replace('{{pct}}',action),
                        _vimeo_urls[data.player_id]
                    ]);
                }
            }
        }
        
        /**
         * Helper function to post messages to a vimeo player
         *
         * @param {string} method The method from the vimeo API.
         * @param {string} params to be passed as the value of the method.
         * @param {object} target Iframe DOM Element for the Vimeo player.
         * @return {boolean} true if it worked or false otherwise.
         */
        function _vimeoPostMessage(method, params, target) {
            if (!target.contentWindow || !target.contentWindow.postMessage || !JSON) {
                return false;
            }
            var url = target.getAttribute('src').split('?')[0],
                data = JSON.stringify({
                    method: method,
                    value: params
                });
            target.contentWindow.postMessage(data, url);
            return true;
        }
        
        
        /**
         * Flag that indicates if the global listener has been bind to the window
         * @type {boolean}
         */
        var _has_vimeo_window_event = false;
        
       
        /**
         * postMessage Listener
         * @param {Object} event The Vimeo API return event.
         */
        /*jshint latedef:false*/
        function _vimeoPostMessageListener(event) {
            if (String.prototype.indexOf.call(event.origin, '//player.vimeo.com') > -1) {
                var data = JSON.parse(event.data);
                if (data.event === 'ready') {
                    _trackVimeo.call(); // Force rerun since a player is ready
                } else if (data.method) {
                    if (data.method === 'getVideoUrl') {
                        _vimeo_urls[data.player_id] = data.value;
                    }
                } else if (data.event === 'playProgress') {
                    _vimeoPool(data);
                } else {
                    
                    var action;
                    if (data.event == 'play'){
                        action = self.action_play;
                    } else if (data.event == 'pause'){
                        action = self.action_pause;
                    } else if (data.event == 'finish'){
                        action = self.action_finish;
                    } else if (data.event == 'seek'){
                        action = self.action_seek;
                    } else {
                        action = data.event;
                    }
                    
                    parent.hit(['_trackEvent', self.category,
                        action, _vimeo_urls[data.player_id]]);
                }
            }
        
        }
        /*jshint latedef:true*/
        
        /**
         * Triggers the Vimeo Tracking on the page
         *
         * Only works for the Universal Tag from Vimeo (iframe). The video must have
         * the parameter api=1 on the url in order to make the tracking work.
         *
         * @this {GasHelper} GA Helper object.
         */

        function _trackVimeo() {
            var iframes = document.getElementsByTagName('iframe');
            var vimeo_videos = 0;
            var player_id;
            var player_src;
            var separator;
            var force = self.force;
            var partials = self.percentages;
            for (var i = 0; i < iframes.length; i++) {
                if (String.prototype.indexOf.call(iframes[i].src, '//player.vimeo.com') > -1) {
                    player_id = 'gas_vimeo_' + i;
                    player_src = iframes[i].src;
                    separator = '?';
                    if (String.prototype.indexOf.call(player_src, '?') > -1) {
                        separator = '&';
                    }
                    if (String.prototype.indexOf.call(player_src, 'api=1') < 0) {
                        if (force) {
                            // Reload the video enabling the api
                            player_src += separator + 'api=1&player_id=' + player_id;
                        } else {
                            // We won't track players that don't have api enabled.
                            continue;
                        }
                    } else {
                        if (String.prototype.indexOf.call(player_src, 'player_id=') < -1) {
                            player_src += separator + 'player_id=' + player_id;
                        }
                    }
                    vimeo_videos++;
                    iframes[i].id = player_id;
                    if (iframes[i].src !== player_src) {
                        iframes[i].src = player_src;
                        break; // break to wait until it is ready since we reloaded it.
                    }
                    // We need to cache the video url since vimeo won't provide it
                    // in the event
                    _vimeoPostMessage('getVideoUrl', '', iframes[i]);
                    _vimeoPostMessage('addEventListener', 'play', iframes[i]);
                    _vimeoPostMessage('addEventListener', 'pause', iframes[i]);
                    _vimeoPostMessage('addEventListener', 'finish', iframes[i]);
                    // Pushes an event when a user goes backward or forwars on a video
                    _vimeoPostMessage('addEventListener', 'seek', iframes[i]);
                    if (partials) {
                        _vimeoTimeTriggers = partials;
                        _vimeoPostMessage('addEventListener', 'playProgress',
                            iframes[i]);
                    }
                }
            }
            if (vimeo_videos > 0 && _has_vimeo_window_event === false) {
                _addEventListener(window, 'message',
                    _vimeoPostMessageListener, false
                );
                _has_vimeo_window_event = true;
            }
        }
        
        //Wait for document ready event, and run the tracking code
        _DOMReady(_trackVimeo);
        
        window._ninja.retrackVimeo = function(){
            _trackVimeo();
        };        
    }

});


/* track youtube events */
_ninja.module_factory.createModule({

    name: 'video-youtube',
    category: 'video',
    action_play: 'play',
    action_pause: 'pause',
    action_progress: 'progress %{{pct}}',
    action_finish: 'finish',
    label_callback: null,
    percentages: [25, 50, 75, 90],
    force: true,    
    run: function(){

        var self = this;
        var parent = _ninja;
        
        /**
         * Array of percentage to fire events.
         */
        var _ytTimeTriggers = [];
       
        
        /**
         * Used to map each vid to a set of timeTriggers and it's pool timer
         */
        var _ytPoolMaps = {};
        
        
        var youtube_videos = {};
        
        var first_time = false;
        
        function _ytPool(target, hash) {
            if (_ytPoolMaps[hash] === undefined ||
                _ytPoolMaps[hash].timeTriggers.length <= 0) {
                return false;
            }
            var p = target['getCurrentTime']() / target['getDuration']() * 100;
            if (p >= _ytPoolMaps[hash].timeTriggers[0]) {
                var action = _ytPoolMaps[hash].timeTriggers.shift();
                parent.hit([
                    '_trackEvent',
                    self.category,
                    self.action_progress.replace('{{pct}}',action),
                    getLabel(target['getVideoUrl']())
                ]);
            }
            _ytPoolMaps[hash].timer = setTimeout(_ytPool, 1000, target, hash);
        }
        
        function _ytStopPool(target) {
            var h = target['getVideoUrl']();
            if (_ytPoolMaps[h] && _ytPoolMaps[h].timer) {
                _ytPool(target, h); // Pool one last time before clearing it.
                clearTimeout(_ytPoolMaps[h].timer);
            }
        }
        
        function _ytStartPool(target) {
            if (_ytTimeTriggers && _ytTimeTriggers.length) {
                var h = target['getVideoUrl']();
                if (_ytPoolMaps[h]) {
                    _ytStopPool(target);
                }else {
                    _ytPoolMaps[h] = {};
                    _ytPoolMaps[h].timeTriggers = Array.prototype.slice.call(_ytTimeTriggers);
                }
                _ytPoolMaps[h].timer = setTimeout(_ytPool, 1000, target, h);
            }
        }
        
        
        /**
         * Called when the Video State changes
         *
         * We are currently tracking only finish, play and pause events
         *
         * @param {Object} event the event passed by the YT api.
         */
        function _ytStateChange(event) {
            var action = '';
            switch (event['data']) {
            case 0:
                action = self.action_finish;
                _ytStopPool(event['target']);
                break;
            case 1:
                action = self.action_play;
                _ytStartPool(event['target']);
                break;
            case 2:
                action = self.action_pause;
                _ytStopPool(event['target']);
                break;
            }
            if (action) {
                parent.hit(['_trackEvent',
                    self.category, action, getLabel(event['target']['getVideoUrl']())
                ]);
            }
        }
        
        /**
         * Called when the player fires an Error Event
         *
         * @param {Object} event the event passed by the YT api.
         */
        function _ytError(event) {
            parent.hit(['_trackEvent',
                self.category,
                'error (' + event['data'] + ')',
                getLabel(event['target']['getVideoUrl']())
            ]);
        }
        
        /**
         * Looks for object/embed youtube videos and migrate them to the iframe method
         *  so it tries to track them
         */
        function _ytMigrateObjectEmbed() {
            var objs = document.getElementsByTagName('object');
            var pars, ifr, ytid;
            var r = /(https?:\/\/www\.youtube(-nocookie)?\.com[^\/]*).*\/v\/([^&?]+)/;
            for (var i = 0; i < objs.length; i++) {
                pars = objs[i].getElementsByTagName('param');
                for (var j = 0; j < pars.length; j++) {
                    if (pars[j].name === 'movie' && pars[j].value) {
                        // Replace the object with an iframe
                        ytid = pars[j].value.match(r);
                        if (ytid && ytid[1] && ytid[3]) {
                            ifr = document.createElement('iframe');
                            ifr.src = ytid[1] + '/embed/' + ytid[3] + '?enablejsapi=1';
                            ifr.width = objs[i].width;
                            ifr.height = objs[i].height;
                            ifr.setAttribute('frameBorder', '0');
                            ifr.setAttribute('allowfullscreen', '');
                            objs[i].parentNode.insertBefore(ifr, objs[i]);
                            objs[i].parentNode.removeChild(objs[i]);
                            // Since we removed the object the Array changed
                            i--;
                        }
                        break;
                    }
                }
            }
        }
        
        /**
         * Triggers the YouTube Tracking on the page
         *
         * Only works for the iframe tag. The video must have the parameter
         * enablejsapi=1 on the url in order to make the tracking work.
         *
         * @param {(object)} opts GAS Options object.
         */
        function _trackYoutube() {
            var force = self.force;
            var opt_timeTriggers = self.percentages;
            
            if (force) {
                try {
                    _ytMigrateObjectEmbed();
                }catch (e) {
                    parent.hit(['_trackException', e,
                        'GAS Error on youtube.js:_ytMigrateObjectEmbed'
                    ]);
                }
            }
        
            var iframes = document.getElementsByTagName('iframe');

            var found_videos = false;
            for (var i = 0; i < iframes.length; i++) {
                
                if (String.prototype.indexOf.call(iframes[i].src, '//www.youtube.com/embed') > -1) {
                    
                    if (iframes[i].className.match(/tracked/)) {
                        continue;
                    } 
                    
                    if (String.prototype.indexOf.call(iframes[i].src, 'enablejsapi=1') < 0) {
                        if (force) {
                            // Reload the video enabling the api
                            if (String.prototype.indexOf.call(iframes[i].src, '?') < 0) {
                                iframes[i].src += '?enablejsapi=1&origin='+encodeURIComponent(location.protocol+'//'+location.hostname);
                            } else {
                                iframes[i].src += '&enablejsapi=1&origin='+encodeURIComponent(location.protocol+'//'+location.hostname);
                            }
                        } else {
                            // We can't track players that don't have api enabled.
                            continue;
                        }
                    }
                    
                    iframes[i].className += ' tracked';
                    youtube_videos[iframes[i].src] = iframes[i];
                    found_videos = true;
                }
            }

            if (found_videos) {
                if (opt_timeTriggers && opt_timeTriggers.length) {
                    _ytTimeTriggers = opt_timeTriggers;
                }

                // this function will be called when the youtube api loads
                window['onYouTubePlayerAPIReady'] = function () {
                        var p;
                        first_time = true;
                        for (var i in youtube_videos) {
                            if (youtube_videos.hasOwnProperty(i)) {
                                p = new window['YT']['Player'](youtube_videos[i]);
                                p.addEventListener('onStateChange', _ytStateChange);
                                p.addEventListener('onError', _ytError);    
                            }
                        }
                    };
                // load the youtube player api
                var tag = document.createElement('script');
                //XXX use document.location.protocol
                var protocol = 'http:';
                if (document.location.protocol === 'https:') {
                    protocol = 'https:';
                }
                tag.src = protocol + '//www.youtube.com/player_api';
                tag.type = 'text/javascript';
                tag.async = true;
                var firstScriptTag = document.getElementsByTagName('script')[0];
                firstScriptTag.parentNode.insertBefore(tag, firstScriptTag);
            }
        }
        
        function getLabel(video_url){
            if (typeof(self.label_callback) === 'function') {
                return self.label_callback(video_url);
            } else {
                return video_url;
            }
        }

        //Wait for document ready event, and run the tracking code
        _DOMReady(_trackYoutube);
        
        window._ninja.retrackYT = function(){
            _trackYoutube();
            //explicitly trigger the onready if we've already run
            if(first_time){
                window['onYouTubePlayerAPIReady']();
            }
        };

    }
    
    
});


//skeleton class for AN engines
function AN_Engine( passed_config ){

    //Base options for every engine
    var skeleton_config = {
        name: '',
        init: function(){},
        run: function(){}
    };

    //Extend the skeleton config with the engines's base configuration options
    var config = extend({},skeleton_config,passed_config);

    //Run the init function for the engine, which runs when the library is run
    config.init();

    return config;
}


//factory object for instantiating and registering AN engines
_ninja.engine_factory = (function(){
    
    //Internal container for all registered engine types. Runtime options will instantiate 
    //engines from this list
    var engine_types = {};
    var engines = [];

    return {
    
        //Pretty simple, all we do is instantiate the engine and register it with the library
        registerEngineClass: function( engine_type_class ){

            //register the new engine class by putting it in the engine_list object
            if(!engine_type_class.type){
                throw "Engine registered with no defined type name";
            }
            engine_types[engine_type_class.type] = engine_type_class ;
            
        },
        createEngine: function( options ){

            if(typeof(options) != 'object'){
                return;
            } 
        
            if(!options.type){
                throw "Engine type not defined in passed options. 'type' attribute must be present in configuration object.";
            }
            
            if(!engine_types[options.type]){
                throw 'Requested engine type [' + options.type + '] does not exist in registry';
            }
            
            var engine = new AN_Engine(extend(true,{},engine_types[options.type],options));
            engines.push(engine);
            
        },
        getEngines: function(){
            return engines;
        }
        
        
    };
    
})();


/*
 * Dummy engine for echoing hits to console
 * This will override debug settings and log to console (if it exists)
 *
 */

/*jshint -W098 */

_ninja.engine_factory.registerEngineClass({

    type: 'echo',
    init: function(){
    
        debug.log("echo engine started");
        
    },
    run: function(){
        
        var args = Array.prototype.slice.call(arguments);
        args.unshift('<ninjalib hit>');
        debug.log(args);

    }
 
});
/*jshint +W098 */


/* definition of engine for pushing events to Google Analytics */

_ninja.engine_factory.registerEngineClass({

    type: 'ga',
    
    //Init code for the engine, run when the library is initialized
    init: function(){

		window['_gaq'] = window['_gaq'] || [];

		(function() {
			var ga = document.createElement('script'); ga.type = 'text/javascript'; ga.async = true;
			ga.src = ('https:' == document.location.protocol ? 'https://ssl' : 'http://www') + '.google-analytics.com/ga.js';
			var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(ga, s);
		  })();
		
		if(this.name){
			this.name_prefix = this.name + '.';
		} else {
			this.name_prefix = '';
		}
		
		var tracker_description = this.name ? 'Named Tracker ' + this.name : 'Unnamed Tracker';
		if(!this.tracker_id){
			debug.log('Registering GA engine for already initialized ' + tracker_description);
		} else {
			debug.log('Initializing GA engine for ' + tracker_description);
			window['_gaq'].push([this.name_prefix + '_setAccount',this.tracker_id]); //Initialize as a named tracker    
		}

    },
    
    run: function(params){
        
		var the_params = params.slice();
	
		the_params[0] = this.name_prefix + the_params[0];
		window['_gaq'].push(the_params);

    },
    
    //To start, lets just deal with GA events
    constructPush: function(params){
        
        if(params[0] == '_trackEvent'){
            return this.constructEvent(params);
        } else {
            return false;
        }
        
    },
      
    constructEvent: function(params){
        
        if(!params[1]){
            return false;
        }
        
        var the_result = {
            category: params[1]
        };
        
        if(params[2]){
            the_result.action = params[2];
        }
        
        if(params[3]){
            the_result.label = params[3];
        }

        if(params[4]){
            the_result.value = params[4];
        }

        if(params[5]){
            the_result.non_interaction = params[5];
        }        

        return the_result;     
    }
 
});

/* definition of engine for pushing hits to Google Tag Manager */

_ninja.engine_factory.registerEngineClass({

    type: 'gtm',

    //Init code for the engine, run when the library is initialized
    init: function() {

        //lets make sure there's a data layer defined
        window.dataLayer = window.dataLayer || [];

    },

    run: function(params) {

        //Translate it into GTM event and push it to the data layer. Decide what to do with the event in the GTM ruleset.
        var push_object = this.constructPush(params);
        push_object.eventSource = 'ninja';

        window.dataLayer.push(push_object);

    },

    //This function receives params from the engine
    //If they're encoded in the old _gaq.push style, reformat them
    //to the appropriate dataLayer variables.
    //If it's an object or an array that we don't recognize, we just pass it
    //through to GTM and decide what to do there.
    constructPush: function(params) {

        var to_push, last_object;

        //if the last argument is an object, merge it with the final
        //constructed hit (for custom dimensions, etc)
        if (typeof(params[params.length - 1]) === 'object') {
            last_object = params.pop();
        }

        if (params[0] && params[0].indexOf('_trackEvent') > -1) {
            to_push = this.constructGAEvent(params);
        } else if (params[0] && params[0].indexOf('_trackPageview') > -1) {
            to_push = this.constructGAPageview(params);
        } else if (params[0] && params[0].indexOf('_trackSocial') > -1) {
            to_push = this.constructGASocial(params);
        } else if (params[0] && params[0].indexOf('_trackTiming') > -1) {
            to_push = this.constructGATiming(params);
        } else if (params[0] && params[0].indexOf('_setPageName') > -1) {
            to_push = this.constructSetPageName(params);
        } else if (params[0] && params[0].indexOf('_setHostname') > -1) {
            to_push = this.constructSetHostname(params);
        } else {
            to_push = {
                "event": "ninja",
                "params": params
            };
        }

        if (last_object) {
            to_push = extend({}, to_push, last_object);
        }

        return to_push;

    },

    constructSetPageName: function(params) {
        return {
            'gaPagePath': params[1]
        };
    },

    constructSetHostname: function(params) {
        return {
            'gaHostname': params[1]
        };
    },

    //Construct a GTM event which mirrors the GA pageview structure
    constructGAPageview: function(params) {

        var pv = {
            "event": "gaPageview"
        };

        if (params[1]) {
            pv.gaPagePath = params[1];
        } else {
            pv.gaPagePath = document.location.pathname;
        }

        return pv;
    },

    //Construct a GTM event which mirrors the GA event structure
    constructGAEvent: function(params) {

        if (!params[1]) {
            return false;
        }

        var event = {
            "event": "gaEvent",
            "gaEventCategory": params[1],
            "gaEventAction": params[2],
            "gaEventLabel": params[3] || '',
            "gaEventValue": params[4] || 0,
            "gaEventNonInteraction": params[5] || false
        };

        // if(params[3]){
        //     event.gaEventLabel = params[3];
        // } else {
        //     event.gaEventLabel = null;
        // }

        // if(params[4]){
        //     event.gaEventValue = params[4];
        // } else {
        //     event.gaEventValue = null;
        // }

        // if(params[5]){
        //     event.gaEventNonInteraction = params[5];
        // } else {
        //     event.gaEventNonInteraction = null;
        // }

        return event;

    },

    //Construct a GTM event which mirrors the GA socialAction structure
    constructGASocial: function(params) {

        var social = {
            "event": "gaSocial",
            "gaSocialActivityNetwork": params[1],
            "gaSocialActivityAction": params[2]
        };

        if (params[3]) {
            social.gaSocialActivityTarget = params[3];
        } else {
            social.gaSocialActivityTarget = null;
        }

        if (params[4]) {
            social.gaSocialActivityPagePath = params[4];
        } else {
            social.gaSocialActivityPagePath = null;
        }

        return social;
    },

    constructGATiming: function(params) {

        var timing = {
            "event": "gaUserTiming",
            "gaUserTimingCategory": params[1],
            "gaUserTimingVariable": params[2],
            "gaUserTimingValue": params[3]
        };

        if (params[4]) {
            timing.gaUserTimingLabel = params[4];
        } else {
            timing.gaUserTimingLabel = null;
        }

        if (params[5]) {
            timing.gaUserTimingSample = params[5];
        } else {
            timing.gaUserTimingSample = null;
        }

        return timing;
    },

    constructGAException: function(params) {
        //TODO
        return params;
    }

});

window._ninja = _ninja;

})(window);
