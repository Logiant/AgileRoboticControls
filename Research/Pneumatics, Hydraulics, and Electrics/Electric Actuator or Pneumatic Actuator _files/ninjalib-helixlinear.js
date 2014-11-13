/*
 * helixlinear v0.92.0
 * Monday, August 18th, 2014, 12:50:43 PM
 * Analytics Ninja implementation code
 */
/*!
 * jQuery Cookie Plugin v1.4.0
 * https://github.com/carhartl/jquery-cookie
 *
 * Copyright 2013 Klaus Hartl
 * Released under the MIT license
 */(function(e){typeof define=="function"&&define.amd?define(["jquery"],e):e(jQuery)})(function(e){function n(e){return u.raw?e:encodeURIComponent(e)}function r(e){return u.raw?e:decodeURIComponent(e)}function i(e){return n(u.json?JSON.stringify(e):String(e))}function s(e){e.indexOf('"')===0&&(e=e.slice(1,-1).replace(/\\"/g,'"').replace(/\\\\/g,"\\"));try{e=decodeURIComponent(e.replace(t," "))}catch(n){return}try{return u.json?JSON.parse(e):e}catch(n){}}function o(t,n){var r=u.raw?t:s(t);return e.isFunction(n)?n(r):r}var t=/\+/g,u=e.cookie=function(t,s,a){if(s!==undefined&&!e.isFunction(s)){a=e.extend({},u.defaults,a);if(typeof a.expires=="number"){var f=a.expires,l=a.expires=new Date;l.setDate(l.getDate()+f)}return document.cookie=[n(t),"=",i(s),a.expires?"; expires="+a.expires.toUTCString():"",a.path?"; path="+a.path:"",a.domain?"; domain="+a.domain:"",a.secure?"; secure":""].join("")}var c=t?undefined:{},h=document.cookie?document.cookie.split("; "):[];for(var p=0,d=h.length;p<d;p++){var v=h[p].split("="),m=r(v.shift()),g=v.join("=");if(t&&t===m){c=o(g,s);break}!t&&(g=o(g))!==undefined&&(c[m]=g)}return c};u.defaults={},e.removeCookie=function(t,n){return e.cookie(t)!==undefined?(e.cookie(t,"",e.extend({},n,{expires:-1})),!0):!1}});
/*
 * https://github.com/google/data-layer-helper
 * Copyright 2012 Google Inc. All rights reserved.
 * jQuery v1.9.1 (c) 2005, 2012
 * jQuery Foundation, Inc. jquery.org/license.
 */
(function(){
    var g=/\[object (Boolean|Number|String|Function|Array|Date|RegExp)\]/;function h(a){return null==a?String(a):(a=g.exec(Object.prototype.toString.call(Object(a))))?a[1].toLowerCase():"object"}function k(a,b){return Object.prototype.hasOwnProperty.call(Object(a),b)}function m(a){if(!a||"object"!=h(a)||a.nodeType||a==a.window)return!1;try{if(a.constructor&&!k(a,"constructor")&&!k(a.constructor.prototype,"isPrototypeOf"))return!1}catch(b){return!1}for(var c in a);return void 0===c||k(a,c)};
    function n(a,b,c){this.b=a;this.f=b||function(){};this.d=!1;this.a={};this.c=[];this.e=p(this);r(this,a,!c);var d=a.push,e=this;a.push=function(){var b=[].slice.call(arguments,0),c=d.apply(a,b);r(e,b);return c}}window.DataLayerHelper=n;n.prototype.get=function(a){var b=this.a;a=a.split(".");for(var c=0;c<a.length;c++){if(void 0===b[a[c]])return;b=b[a[c]]}return b};n.prototype.flatten=function(){this.b.splice(0,this.b.length);this.b[0]={};s(this.a,this.b[0])};
    function r(a,b,c){for(a.c.push.apply(a.c,b);!1===a.d&&0<a.c.length;){b=a.c.shift();if("array"==h(b))a:{var d=b,e=a.a;if("string"==h(d[0])){for(var f=d[0].split("."),u=f.pop(),d=d.slice(1),l=0;l<f.length;l++){if(void 0===e[f[l]])break a;e=e[f[l]]}try{e[u].apply(e,d)}catch(v){}}}else if("function"==typeof b)try{b.call(a.e)}catch(w){}else if(m(b))for(var q in b)s(t(q,b[q]),a.a);else continue;c||(a.d=!0,a.f(a.a,b),a.d=!1)}}
    function p(a){return{set:function(b,c){s(t(b,c),a.a)},get:function(b){return a.get(b)}}}function t(a,b){for(var c={},d=c,e=a.split("."),f=0;f<e.length-1;f++)d=d[e[f]]={};d[e[e.length-1]]=b;return c}function s(a,b){for(var c in a)if(k(a,c)){var d=a[c];"array"==h(d)?("array"==h(b[c])||(b[c]=[]),s(d,b[c])):m(d)?(m(b[c])||(b[c]={}),s(d,b[c])):b[c]=d}};
})();
(function(){
"use strict";

/* jshint browser:true */
/* global GaCookiesNinja,helper */

window.helper = new window.DataLayerHelper(dataLayer);

//Get/store the campaign values including first touch data
$.cookie.raw = true;

var COOKIE_OPTIONS = {path: '/'};

(function() {

    var gcn = new GaCookiesNinja();

    /**
     * Fix data layer
     */
    (function fixDataLayer(){

        //Write certain data layer values to first-party cookies for access via GTM macro
        if(helper.get('customer.accountName')){
            var accountName = helper.get('customer.accountName');
            $.cookie('company',accountName,COOKIE_OPTIONS);
        }

        if(helper.get('customer.industry')){
            var industry = helper.get('customer.industry');
            $.cookie('industry',industry,COOKIE_OPTIONS);
        }

        if(helper.get('customer.contactID')){
            $.cookie('contactID',helper.get('customer.contactID'),COOKIE_OPTIONS);
        }

    })();


    $.cookie.json = true;
    $.cookie.raw = false;
    //write the first touch cookie values if applicable
    if (gcn.getSessionCounter() == 1) {
        $.cookie('first_touch', {
            gaFirstSource: gcn.getCampaignSource(),
            gaFirstMedium: gcn.getCampaignMedium(),
            gaFirstCampaign: gcn.getCampaignName(),
            gaFirstAdContent: gcn.getCampaignContent(),
            gaFirstKeyword: gcn.getCampaignTerm(),
            gaFirstVisitDate: gcn.ninja.firstVisitString
        }, COOKIE_OPTIONS);
    }
    //read the first touch cookie if it's available
    var ft_cookie = $.cookie('first_touch');
    $.cookie.json = false;
    $.cookie.raw = true;

    //the basic campaign values from the current session
    window.campaign_values = {
        gaClientID: gcn.getUniqueId(),
        gaVisitSource: gcn.getCampaignSource(),
        gaVisitMedium: gcn.getCampaignMedium(),
        gaVisitCampaign: gcn.getCampaignName(),
        gaVisitAdContent: gcn.getCampaignContent(),
        gaVisitKeyword: gcn.getCampaignTerm()
    };

    if (ft_cookie) {
        window.campaign_values = $.extend({}, window.campaign_values, ft_cookie);
    }

})();



_ninja.init({
    debug: false,
    implementationVersion: '0.92.0',
    engines: [{
        type: 'gtm'
    }]
});



jQuery(function() {

    //Get the product name on product pages
    //Replace with dataLayer value when that becomes available
    var product_name = jQuery.trim(jQuery('div.main > section > h1').text());

    var current_menu_category;


    /*
     * ALL PAGES
     */

    // Top Links Clicks . All Pages
    $(document).on('mousedown', '.right > li a', function() {
        _ninja.hit(['_trackEvent', 'Top Navigation', jQuery.trim($(this).text())]);
    });

    // Top 3 Boxes. All Pages.
    $(document).on('mousedown', '.grid_2 a', function() {
        _ninja.hit(['_trackEvent', 'Top Boxes', jQuery.trim($(this).text())]);
    });

    // Nav Bar
    $(document).on('mouseover', '.top.jq_nav', function() {
        current_menu_category = jQuery.trim($(this).text().trim());
    });

    $(document).on('mousedown', 'a.jq_nav', function() {
        var subcat = jQuery.trim($(this).text());
        if (current_menu_category == subcat)
            subcat = 'Main';
        _ninja.hit(['_trackEvent', 'Primary Navigation', current_menu_category, subcat]);
    });

    // Catalog downloads, from NavBar Footer
    $(document).on('mousedown', '.dropdown > .footer a', function() {
        _ninja.hit(['_trackEvent', 'Primary Navigation', current_menu_category, jQuery.trim($(this).text())]);
    });

    jQuery(document).on('mousedown', 'a.cta_button', function() {
        _ninja.hit(['_trackEvent', 'CTA', 'Blog', jQuery(this).find('img').attr('alt')]);
    });

    //Clicks on footer navigation links
    jQuery(document).on('mousedown', 'footer a', function() {
        var category = jQuery(this).parent().prevAll().find('strong').first().text().replace(':', '');
        _ninja.hit(['_trackEvent', 'Footer Navigation', category, jQuery(this).text()]);
    });

    //Chat events
    jQuery(document).on('mousedown', '#smMainChatDiv #smChatCtrl', function() {
        _ninja.hit(['_trackEvent', 'Chat', 'Open Chat Window']);
    });

    // Submit listener for Top Search Form
    jQuery(document).on('submit', 'form[name="formSearch"]', function() {
        var search_query = jQuery.trim($('form[name="formSearch"] > input').val());
        _ninja.hit(['_trackPageview', '/search-results/?q=' + search_query]);
    });

    /*
     * PRODUCT GROUP PAGES
     */

    // Quick Link Overlay ie: http://www.helixlinear.com/Product/ProductGroup/Screws

    jQuery(document).on('change', 'select[name=id]', function() {
        _ninja.hit(['_trackEvent', 'Quick Link Overlay', jQuery.trim($(this).parent().prev('h1').text()), jQuery.trim($('select[name=id] option:selected').text())]);
    });

    /*
     * FORM ERROR TRACKING
     */

    // Any Contact form on the page, each error displayed after form submit will generate a error event
    jQuery('.field-validation-error').each(function() {
        _ninja.hit(['_trackEvent', 'Form Errors', location.pathname, jQuery.trim($(this).text())]);
    });


    // This one is gonna fire a event for each error showed on the configuration tool
    jQuery('form font[color="red"]').each(function() {
        _ninja.hit(['_trackEvent', 'Configuration Tool Errors', jQuery.trim($(this).prev('label').text()), jQuery.trim($(this).text())]);
    });


    // Right Accordion Categories clicks
    $(document).on('mousedown', '.accordion h3 ', function() {
        _ninja.hit(['_trackEvent', 'Right Accordion', jQuery.trim($(this).text())]);
    });

    // Right Accordion Links clicks
    $(document).on('mousedown', '.pane a', function() {
    	// Avoid sending this event on related product tab
	if($(this).parents('li').size()>0)
        {
           var accordion_cat = $(this).closest('div').prev().text().trim();
           _ninja.hit(['_trackEvent', 'Right Accordion', accordion_cat, jQuery.trim($(this).text())]);
        }
    });


    /* Category Navigation */

    //Get the current category by reading the breadcrumbs
    var breadcrumb_array = jQuery.map(jQuery('.breadcrumbs').text().split('/'), function(x) {
        return jQuery.trim(x);
    });

    var breadcrumbs;
    if (document.location.pathname.match(/\/Product\/Wizard/)) {
        breadcrumbs = breadcrumb_array.slice(1, -1).join(' / ');
    } else {
        breadcrumbs = breadcrumb_array.slice(1).join(' / ');
    }

    jQuery('body.ProductGroup section.productList a,.productLine div.item,td.productTD a').unbind('mousedown').bind('mousedown', function() {
        var clicked_product = jQuery.trim(jQuery(this).text());
        _ninja.hit(['_trackEvent', 'Finding a Product', breadcrumbs, clicked_product]);
    });

    jQuery('form[name=form1] select').unbind('change').bind('change', function() {
        var clicked_product = jQuery.trim(jQuery(this).find('option:selected').text());
        _ninja.hit(['_trackEvent', 'Finding a Product', breadcrumbs, clicked_product]);
    });


    /*
     * HOMEPAGE
     */

    jQuery('body.home').each(function() {

        //Feature Scroll Navigation
        jQuery(document).on('mousedown', 'div.feature div.item', function() {
            _ninja.hit(['_trackEvent', 'Homepage', 'Feature Scroll Navigation', jQuery.trim(jQuery(this).text())]);
        });

        //Clicks on links to blog posts
        jQuery(document).on('mousedown', 'div.news a', function() {
            _ninja.hit(['_trackEvent', 'Homepage', 'News Link', jQuery.trim(jQuery(this).find('.post').text())]);
        });

        //Homepage CTAs
        jQuery(document).on('mousedown', 'div.ctas a', function() {
            _ninja.hit(['_trackEvent', 'CTA', jQuery.trim(jQuery(this).text())]);
        });

    });


    /*
     * PRODUCT PAGES
     */

    jQuery('body.ProductName').each(function() {

        //Request Quote
        jQuery(document).on('mousedown', 'p.buy a', function() {
            _ninja.hit(['_trackEvent', 'Product Page', 'Request Quote', product_name]);
        });

        //Download product spec
        jQuery(document).on('mousedown', 'p.download a[href*=ProductSpec]', function() {
            _ninja.hit(['_trackEvent', 'Product Page', 'Download Spec Sheet', product_name]);
        });

        //Click to view a different thumbnail
        jQuery(document).on('mousedown', 'section.gallery ul.ui-tabs-nav li a img', function() {
            _ninja.hit(['_trackEvent', 'Product Page', 'Select Thumbnail', this.src]);
        });

        //Click to download thumbnail
        jQuery(document).on('mousedown', 'section.gallery div.pic img', function() {
            _ninja.hit(['_trackEvent', 'Product Page', 'Download Thumbnail', this.src]);
        });

        //Click on one of the information tabs on the product page
        jQuery(document).on('mousedown', 'section.datagrid div.tabs ul.ui-tabs-nav a', function() {
            _ninja.hit(['_trackEvent', 'Product Page', 'Tab Select', jQuery(this).text()]);
        });

        //View Compatible Product
        jQuery(document).on('mousedown', 'section.datagrid div.tab:last a', function() {
            _ninja.hit(['_trackEvent', 'Product Page', 'View Compatible Product', jQuery(this).text()]);
        });

        //On pages with the configurator, track timing of the form
        var load_start;
        jQuery('iframe#configurator').contents().on('mousedown', 'input[type=button]', function() {
            load_start = new Date();
            _ninja.hit(['_trackEvent', 'Product Page', 'Configure', product_name]);
        });


        jQuery('iframe#configured').load(function() {
            //If we havent initialized load_start, this is the original load, which we don't track
            if (load_start) {
                var load_end = new Date();
                var total_time = load_end.getTime() - load_start.getTime();

                _ninja.hit(['_trackTiming', 'Configurator', 'Configurator Load Time', total_time, product_name]);
                _ninja.hit(['_trackEvent', 'Product Page', 'Reconfigure', product_name]);
            }

            jQuery(this).contents().on('mousedown', 'div.buttons div.generateModel a', function() {

                var action;

                if (!jQuery(this).parent().data('action')) {
                    action = jQuery(this).text().replace('Generate ', '');
                    jQuery(this).parent().data('action', action);
                    _ninja.hit(['_trackEvent', 'Product Page', 'Generate Model: ' + action, product_name]);
                } else {
                    action = jQuery(this).parent().data('action');
                    _ninja.hit(['_trackEvent', 'Product Page', 'Download Model: ' + action, product_name]);
                }
            });

            jQuery(this).contents().on('mousedown', 'div.buttons div.cartQuoteButton a', function() {

                if (!jQuery(this).parent().data('action')) {
                    jQuery(this).parent().data('action', 'added');
                    _ninja.hit(['_trackEvent', 'Product Page', 'Add to Cart', product_name]);
                } else {
                    _ninja.hit(['_trackEvent', 'Product Page', 'Go to Cart', product_name]);
                }

            });

        });


    });

    //This will be removed once the Helix Linear devs put the code in place as outlined in
    //https://gist.github.com/eliyahud/c957382c572975008afd
    $(document).ajaxComplete(function(event, xhr, settings) {
        if (settings.url.match(/\/Cart/)) {
            dataLayer.push({
                'cart': jQuery.parseJSON(xhr.responseText),
                'event': 'cart-updated'
            });
        }
    });
    //Push the original cart, in case we missed it
    if (window.nookind_var && window.nookind_var.cart) {
        dataLayer.push({
            'cart': window.nookind_var.cart,
            'event': 'cart-updated'
        });
    }

    jQuery(document).on('submit', 'body.RFQ form,body.CustomerCare.ContactUs form,body.Catalog.Index form,body.RequestQuote', function() {
        $.cookie('company', jQuery('#company').val(), COOKIE_OPTIONS);
        $.cookie('industry', jQuery('select[name=industry] option:selected').text(), COOKIE_OPTIONS);
        $.cookie('anticipated_purchase', jQuery('select[name*=buytime] option:selected').text(), COOKIE_OPTIONS);

    });


    //Blog subscribe
    jQuery('div[data-widget-type="blog_subscribe"] form').submit(function() {
        _ninja.hit(['_trackPageview', '/newsletter-subscribe']);
    });

    //Blog presentation download
    jQuery(document).on('mousedown', 'body.hs-blog-post .hs-cta-wrapper a', function() {
        var presentation_name = jQuery(this).find('img').attr('alt');
        _ninja.hit(['_trackEvent', 'Blog', 'Download Presentation', presentation_name]);
    });

    jQuery(document).on('mousedown', '.hs_cos_wrapper_type_follow_me a', function() {
        var network_name = this.className.replace('fm_button fm_', '');
        _ninja.hit(['_trackEvent', 'Social Follow', network_name, document.location.pathname]);
    });

    // Catalog/Index PV on request
    jQuery('form[action="/Catalog/Index"]').on('submit',function(){
        _ninja.hit(['_trackPageview', '/catalog/mail-request']);
    });

    if(document.location.pathname.match(/CustomerConnect\/ConfigurationHistory/)){
        jQuery('table a').mousedown(function(){
            _ninja.hit(['_trackEvent','Configuration History','Go',jQuery(this).parent().prev().text()]);
        });
    }

    if(document.location.pathname.match(/CustomerConnect\/DownloadHistory/)){
        jQuery('table input[type=submit]').click(function(){
            var id = jQuery(this).parents('td').prev().text();
            var filetype = jQuery(this).parent().attr('action').match(/filetype=(.*)/)[1];
            var label = [id,filetype].join(':');
            _ninja.hit(['_trackEvent','Download History','Download Model',label]);
        });
    }
    
    //Add campaign values as hidden form fields
    jQuery('form').not('[action*=Search]').each(function() {

		var field_lookup_table = {
			'hubspot': {
				gaVisitSource: 'gaVisitSource',
				gaVisitMedium: 'gaVisitMedium',
				gaVisitCampaign: 'gaVisitCampaign',
				gaVisitAdContent: 'gaVisitAdContent',
				gaVisitKeyword: 'gaVisitKeyword',
				gaClientID: 'gaClientId',
				gaFirstSource: 'gaFirstSource',
				gaFirstMedium: 'gaFirstMedium',
				gaFirstCampaign: 'gaFirstCampaign',
				gaFirstAdContent: 'gaFirstAdContent',
				gaFirstKeyword: 'gaFirstKeyword',
				gaFirstVisitDate: 'gaFirstVisitDate'
			},
			'salesforce': {
				gaVisitSource: '00Na000000BNY9E',
				gaVisitMedium: '00Na000000BNYAv',
				gaVisitCampaign: '00Na000000BNYB5',
				gaVisitAdContent: '00Na000000BNYBA',
				gaVisitKeyword: '00Na000000BNYBF',
				gaClientID: '00Na000000BNYBo',
				gaFirstSource: '00Na000000BNYBK',
				gaFirstMedium: '00Na000000BNYBP',
				gaFirstCampaign: '00Na000000BNYBU',
				gaFirstAdContent: '00Na000000BNYBZ',
				gaFirstKeyword: '00Na000000BNYBe',
				gaFirstVisitDate: '00Na000000BNYBj'
			}
		};

		var types = ['salesforce','hubspot'];
		for(var j = 0; j < types.length; j++) {

			var form_type = types[j];

			for (var i in window.campaign_values) {

				if (window.campaign_values.hasOwnProperty(i)) {
					jQuery('<input />').attr({
						name:             field_lookup_table[form_type][ i ],
						value:            window.campaign_values[i],
						type:             'hidden',
						'data-form-type': form_type
					}).appendTo(jQuery(this));
				}
			}

		}

    });

});

})();