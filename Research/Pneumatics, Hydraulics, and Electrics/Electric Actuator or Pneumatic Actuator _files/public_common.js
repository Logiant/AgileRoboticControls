((function(){var a,b,c,d;window.hs_show_tools_menu_if_author=function(){var b,c,d,e,f,g;if(window.location!==window.parent.location)return;return c=hsVars.page_id,b=hsVars.content_group_id,e=hsVars.portal_id,f=c,c&&b?g="blog-posts":b?(g="blogs",f=b):g="landing-pages",d=hsVars.app_hs_base_url+("/content/api/v2/"+g+"/"+f+"/has-permission?portal_id=")+e,jQuery.ajax(d,{dataType:"jsonp",success:function(b){if(b.has_permission)return a(g,f,e)}})},a=function(a,b,c){return jQuery.ajax(hsVars.app_hs_base_url+("/content/api/v2/"+a+"/"+b+"/tools-menu-actions?portalId="+c),{dataType:"jsonp",success:function(a){if(a.actions)return d(a.actions)}})},d=function(a){var b,d,e,f,g,h,i,j,k,l,m;h=hsVars.page_id,i=hsVars.portal_id,g=jQuery.find("[data-sitemap-name]"),f=g.length>0?g[0]:null,f!=null&&(k=""+hsVars.app_hs_base_url+"/content/"+i+"/settings/site-maps",j=jQuery(f).attr("data-sitemap-name"),a.push(["Edit Navigation Menu",k+("?site-map-name="+j)])),e="";for(l=0,m=a.length;l<m;l++)d=a[l],e+='<li><a target="_blank" href=\''+d[1]+"'>\n    "+d[0]+"\n</a></li>";return b=jQuery("<div class='hs-tools-menu hs-collapsed'>\n    <img class='hs-sprocket' src='http://cdn2.hubspot.net/static/sprocket_white_80.png'>\n    <div class='hs-dropdown'>\n        <div class='hs-title'>HubSpot Tools</div>\n        <ul>\n            "+e+'\n            <li class="hs-menu-hider"><a>Hide This Menu</a></li>\n        </ul>\n    </div>\n</div>'),jQuery("body").append(b),c()},c=function(){var a;return a=jQuery(".hs-tools-menu"),b(a),a.find(".hs-menu-hider").click(function(b){return b.stopPropagation(),a.hide()})},b=function(a){var b,c,d,e,f,g;return d=a.find(".hs-dropdown"),e=function(){return a.addClass("hs-collapsed")},f=function(){return a.removeClass("hs-collapsed")},c=jQuery("body"),b=function(a){return c.bind("click.hs-tools-menu",a)},g=function(){return c.unbind(".hs-tools-menu")},a.bind("click",function(c){if(jQuery(c.target).attr("href"))return;return c.preventDefault(),c.stopPropagation(),a.hasClass("hs-collapsed")?(f(),b(function(){return e(),g()})):(e(),g())})}})).call(this),function(a){a.flexslider=function(b,c){var d=a(b);d.vars=a.extend({},a.flexslider.defaults,c);var e=d.vars.namespace,f=window.navigator&&window.navigator.msPointerEnabled&&window.MSGesture,g=("ontouchstart"in window||f||window.DocumentTouch&&document instanceof DocumentTouch)&&d.vars.touch,h="click touchend MSPointerUp",i="",j,k=d.vars.direction==="vertical",l=d.vars.reverse,m=d.vars.itemWidth>0,n=d.vars.animation==="fade",o=d.vars.asNavFor!=="",p={},q=!0;a.data(b,"flexslider",d),p={init:function(){d.animating=!1,d.currentSlide=parseInt(d.vars.startAt?d.vars.startAt:0),isNaN(d.currentSlide)&&(d.currentSlide=0),d.animatingTo=d.currentSlide,d.atEnd=d.currentSlide===0||d.currentSlide===d.last,d.containerSelector=d.vars.selector.substr(0,d.vars.selector.search(" ")),d.slides=a(d.vars.selector,d),d.container=a(d.containerSelector,d),d.count=d.slides.length,d.syncExists=a(d.vars.sync).length>0,d.vars.animation==="slide"&&(d.vars.animation="swing"),d.prop=k?"top":"marginLeft",d.args={},d.manualPause=!1,d.stopped=!1,d.started=!1,d.startTimeout=null,d.transitions=!d.vars.video&&!n&&d.vars.useCSS&&function(){var a=document.createElement("div"),b=["perspectiveProperty","WebkitPerspective","MozPerspective","OPerspective","msPerspective"];for(var c in b)if(a.style[b[c]]!==undefined)return d.pfx=b[c].replace("Perspective","").toLowerCase(),d.prop="-"+d.pfx+"-transform",!0;return!1}(),d.vars.controlsContainer!==""&&(d.controlsContainer=a(d.vars.controlsContainer).length>0&&a(d.vars.controlsContainer)),d.vars.manualControls!==""&&(d.manualControls=a(d.vars.manualControls).length>0&&a(d.vars.manualControls)),d.vars.randomize&&(d.slides.sort(function(){return Math.round(Math.random())-.5}),d.container.empty().append(d.slides)),d.doMath(),d.setup("init"),d.vars.controlNav&&p.controlNav.setup(),d.vars.directionNav&&p.directionNav.setup(),d.vars.keyboard&&(a(d.containerSelector).length===1||d.vars.multipleKeyboard)&&a(document).bind("keyup",function(a){var b=a.keyCode;if(!d.animating&&(b===39||b===37)){var c=b===39?d.getTarget("next"):b===37?d.getTarget("prev"):!1;d.flexAnimate(c,d.vars.pauseOnAction)}}),d.vars.mousewheel&&d.bind("mousewheel",function(a,b,c,e){a.preventDefault();var f=b<0?d.getTarget("next"):d.getTarget("prev");d.flexAnimate(f,d.vars.pauseOnAction)}),d.vars.pausePlay&&p.pausePlay.setup(),d.vars.slideshow&&d.vars.pauseInvisible&&p.pauseInvisible.init();if(d.vars.slideshow){d.vars.pauseOnHover&&d.hover(function(){!d.manualPlay&&!d.manualPause&&d.pause()},function(){!d.manualPause&&!d.manualPlay&&!d.stopped&&d.play()});if(!d.vars.pauseInvisible||!p.pauseInvisible.isHidden())d.vars.initDelay>0?d.startTimeout=setTimeout(d.play,d.vars.initDelay):d.play()}o&&p.asNav.setup(),g&&d.vars.touch&&p.touch(),(!n||n&&d.vars.smoothHeight)&&a(window).bind("resize orientationchange focus",p.resize),d.find("img").attr("draggable","false"),setTimeout(function(){d.vars.start(d)},200)},asNav:{setup:function(){d.asNav=!0,d.animatingTo=Math.floor(d.currentSlide/d.move),d.currentItem=d.currentSlide,d.slides.removeClass(e+"active-slide").eq(d.currentItem).addClass(e+"active-slide"),f?(b._slider=d,d.slides.each(function(){var b=this;b._gesture=new MSGesture,b._gesture.target=b,b.addEventListener("MSPointerDown",function(a){a.preventDefault(),a.currentTarget._gesture&&a.currentTarget._gesture.addPointer(a.pointerId)},!1),b.addEventListener("MSGestureTap",function(b){b.preventDefault();var c=a(this),e=c.index();!a(d.vars.asNavFor).data("flexslider").animating&&!c.hasClass("active")&&(d.direction=d.currentItem<e?"next":"prev",d.flexAnimate(e,d.vars.pauseOnAction,!1,!0,!0))})})):d.slides.click(function(b){b.preventDefault();var c=a(this),f=c.index(),g=c.offset().left-a(d).scrollLeft();g<=0&&c.hasClass(e+"active-slide")?d.flexAnimate(d.getTarget("prev"),!0):!a(d.vars.asNavFor).data("flexslider").animating&&!c.hasClass(e+"active-slide")&&(d.direction=d.currentItem<f?"next":"prev",d.flexAnimate(f,d.vars.pauseOnAction,!1,!0,!0))})}},controlNav:{setup:function(){d.manualControls?p.controlNav.setupManual():p.controlNav.setupPaging()},setupPaging:function(){var b=d.vars.controlNav==="thumbnails"?"control-thumbs":"control-paging",c=1,f,g;d.controlNavScaffold=a('<ol class="'+e+"control-nav "+e+b+'"></ol>');if(d.pagingCount>1)for(var j=0;j<d.pagingCount;j++){g=d.slides.eq(j),f=d.vars.controlNav==="thumbnails"?'<img src="'+g.attr("data-thumb")+'"/>':"<a>"+c+"</a>";if("thumbnails"===d.vars.controlNav&&!0===d.vars.thumbCaptions){var k=g.attr("data-thumbcaption");""!=k&&undefined!=k&&(f+='<span class="'+e+'caption">'+k+"</span>")}d.controlNavScaffold.append("<li>"+f+"</li>"),c++}d.controlsContainer?a(d.controlsContainer).append(d.controlNavScaffold):d.append(d.controlNavScaffold),p.controlNav.set(),p.controlNav.active(),d.controlNavScaffold.delegate("a, img",h,function(b){b.preventDefault();if(i===""||i===b.type){var c=a(this),f=d.controlNav.index(c);c.hasClass(e+"active")||(d.direction=f>d.currentSlide?"next":"prev",d.flexAnimate(f,d.vars.pauseOnAction))}i===""&&(i=b.type),p.setToClearWatchedEvent()})},setupManual:function(){d.controlNav=d.manualControls,p.controlNav.active(),d.controlNav.bind(h,function(b){b.preventDefault();if(i===""||i===b.type){var c=a(this),f=d.controlNav.index(c);c.hasClass(e+"active")||(f>d.currentSlide?d.direction="next":d.direction="prev",d.flexAnimate(f,d.vars.pauseOnAction))}i===""&&(i=b.type),p.setToClearWatchedEvent()})},set:function(){var b=d.vars.controlNav==="thumbnails"?"img":"a";d.controlNav=a("."+e+"control-nav li "+b,d.controlsContainer?d.controlsContainer:d)},active:function(){d.controlNav.removeClass(e+"active").eq(d.animatingTo).addClass(e+"active")},update:function(b,c){d.pagingCount>1&&b==="add"?d.controlNavScaffold.append(a("<li><a>"+d.count+"</a></li>")):d.pagingCount===1?d.controlNavScaffold.find("li").remove():d.controlNav.eq(c).closest("li").remove(),p.controlNav.set(),d.pagingCount>1&&d.pagingCount!==d.controlNav.length?d.update(c,b):p.controlNav.active()}},directionNav:{setup:function(){var b=a('<ul class="'+e+'direction-nav"><li><a class="'+e+'prev" href="#">'+d.vars.prevText+'</a></li><li><a class="'+e+'next" href="#">'+d.vars.nextText+"</a></li></ul>");d.controlsContainer?(a(d.controlsContainer).append(b),d.directionNav=a("."+e+"direction-nav li a",d.controlsContainer)):(d.append(b),d.directionNav=a("."+e+"direction-nav li a",d)),p.directionNav.update(),d.directionNav.bind(h,function(b){b.preventDefault();var c;if(i===""||i===b.type)c=a(this).hasClass(e+"next")?d.getTarget("next"):d.getTarget("prev"),d.flexAnimate(c,d.vars.pauseOnAction);i===""&&(i=b.type),p.setToClearWatchedEvent()})},update:function(){var a=e+"disabled";d.pagingCount===1?d.directionNav.addClass(a).attr("tabindex","-1"):d.vars.animationLoop?d.directionNav.removeClass(a).removeAttr("tabindex"):d.animatingTo===0?d.directionNav.removeClass(a).filter("."+e+"prev").addClass(a).attr("tabindex","-1"):d.animatingTo===d.last?d.directionNav.removeClass(a).filter("."+e+"next").addClass(a).attr("tabindex","-1"):d.directionNav.removeClass(a).removeAttr("tabindex")}},pausePlay:{setup:function(){var b=a('<div class="'+e+'pauseplay"><a></a></div>');d.controlsContainer?(d.controlsContainer.append(b),d.pausePlay=a("."+e+"pauseplay a",d.controlsContainer)):(d.append(b),d.pausePlay=a("."+e+"pauseplay a",d)),p.pausePlay.update(d.vars.slideshow?e+"pause":e+"play"),d.pausePlay.bind(h,function(b){b.preventDefault();if(i===""||i===b.type)a(this).hasClass(e+"pause")?(d.manualPause=!0,d.manualPlay=!1,d.pause()):(d.manualPause=!1,d.manualPlay=!0,d.play());i===""&&(i=b.type),p.setToClearWatchedEvent()})},update:function(a){a==="play"?d.pausePlay.removeClass(e+"pause").addClass(e+"play").html(d.vars.playText):d.pausePlay.removeClass(e+"play").addClass(e+"pause").html(d.vars.pauseText)}},touch:function(){var a,c,e,g,h,i,j=!1,o=0,p=0,q=0;if(!f){b.addEventListener("touchstart",r,!1);function r(f){if(d.animating)f.preventDefault();else if(window.navigator.msPointerEnabled||f.touches.length===1)d.pause(),g=k?d.h:d.w,i=Number(new Date),o=f.touches[0].pageX,p=f.touches[0].pageY,e=m&&l&&d.animatingTo===d.last?0:m&&l?d.limit-(d.itemW+d.vars.itemMargin)*d.move*d.animatingTo:m&&d.currentSlide===d.last?d.limit:m?(d.itemW+d.vars.itemMargin)*d.move*d.currentSlide:l?(d.last-d.currentSlide+d.cloneOffset)*g:(d.currentSlide+d.cloneOffset)*g,a=k?p:o,c=k?o:p,b.addEventListener("touchmove",s,!1),b.addEventListener("touchend",t,!1)}function s(b){o=b.touches[0].pageX,p=b.touches[0].pageY,h=k?a-p:a-o,j=k?Math.abs(h)<Math.abs(o-c):Math.abs(h)<Math.abs(p-c);var f=500;if(!j||Number(new Date)-i>f)b.preventDefault(),!n&&d.transitions&&(d.vars.animationLoop||(h/=d.currentSlide===0&&h<0||d.currentSlide===d.last&&h>0?Math.abs(h)/g+2:1),d.setProps(e+h,"setTouch"))}function t(f){b.removeEventListener("touchmove",s,!1);if(d.animatingTo===d.currentSlide&&!j&&h!==null){var k=l?-h:h,m=k>0?d.getTarget("next"):d.getTarget("prev");d.canAdvance(m)&&(Number(new Date)-i<550&&Math.abs(k)>50||Math.abs(k)>g/2)?d.flexAnimate(m,d.vars.pauseOnAction):n||d.flexAnimate(d.currentSlide,d.vars.pauseOnAction,!0)}b.removeEventListener("touchend",t,!1),a=null,c=null,h=null,e=null}}else{b.style.msTouchAction="none",b._gesture=new MSGesture,b._gesture.target=b,b.addEventListener("MSPointerDown",u,!1),b._slider=d,b.addEventListener("MSGestureChange",v,!1),b.addEventListener("MSGestureEnd",w,!1);function u(a){a.stopPropagation(),d.animating?a.preventDefault():(d.pause(),b._gesture.addPointer(a.pointerId),q=0,g=k?d.h:d.w,i=Number(new Date),e=m&&l&&d.animatingTo===d.last?0:m&&l?d.limit-(d.itemW+d.vars.itemMargin)*d.move*d.animatingTo:m&&d.currentSlide===d.last?d.limit:m?(d.itemW+d.vars.itemMargin)*d.move*d.currentSlide:l?(d.last-d.currentSlide+d.cloneOffset)*g:(d.currentSlide+d.cloneOffset)*g)}function v(a){a.stopPropagation();var c=a.target._slider;if(!c)return;var d=-a.translationX,f=-a.translationY;q+=k?f:d,h=q,j=k?Math.abs(q)<Math.abs(-d):Math.abs(q)<Math.abs(-f);if(a.detail===a.MSGESTURE_FLAG_INERTIA){setImmediate(function(){b._gesture.stop()});return}if(!j||Number(new Date)-i>500)a.preventDefault(),!n&&c.transitions&&(c.vars.animationLoop||(h=q/(c.currentSlide===0&&q<0||c.currentSlide===c.last&&q>0?Math.abs(q)/g+2:1)),c.setProps(e+h,"setTouch"))}function w(b){b.stopPropagation();var d=b.target._slider;if(!d)return;if(d.animatingTo===d.currentSlide&&!j&&h!==null){var f=l?-h:h,k=f>0?d.getTarget("next"):d.getTarget("prev");d.canAdvance(k)&&(Number(new Date)-i<550&&Math.abs(f)>50||Math.abs(f)>g/2)?d.flexAnimate(k,d.vars.pauseOnAction):n||d.flexAnimate(d.currentSlide,d.vars.pauseOnAction,!0)}a=null,c=null,h=null,e=null,q=0}}},resize:function(){!d.animating&&d.is(":visible")&&(m||d.doMath(),n?p.smoothHeight():m?(d.slides.width(d.computedW),d.update(d.pagingCount),d.setProps()):k?(d.viewport.height(d.h),d.setProps(d.h,"setTotal")):(d.vars.smoothHeight&&p.smoothHeight(),d.newSlides.width(d.computedW),d.setProps(d.computedW,"setTotal")))},smoothHeight:function(a){if(!k||n){var b=n?d:d.viewport;a?b.animate({height:d.slides.eq(d.animatingTo).height()},a):b.height(d.slides.eq(d.animatingTo).height())}},sync:function(b){var c=a(d.vars.sync).data("flexslider"),e=d.animatingTo;switch(b){case"animate":c.flexAnimate(e,d.vars.pauseOnAction,!1,!0);break;case"play":!c.playing&&!c.asNav&&c.play();break;case"pause":c.pause()}},pauseInvisible:{visProp:null,init:function(){var a=["webkit","moz","ms","o"];if("hidden"in document)return"hidden";for(var b=0;b<a.length;b++)a[b]+"Hidden"in document&&(p.pauseInvisible.visProp=a[b]+"Hidden");if(p.pauseInvisible.visProp){var c=p.pauseInvisible.visProp.replace(/[H|h]idden/,"")+"visibilitychange";document.addEventListener(c,function(){p.pauseInvisible.isHidden()?d.startTimeout?clearTimeout(d.startTimeout):d.pause():d.started?d.play():d.vars.initDelay>0?setTimeout(d.play,d.vars.initDelay):d.play()})}},isHidden:function(){return document[p.pauseInvisible.visProp]||!1}},setToClearWatchedEvent:function(){clearTimeout(j),j=setTimeout(function(){i=""},3e3)}},d.flexAnimate=function(b,c,f,h,i){!d.vars.animationLoop&&b!==d.currentSlide&&(d.direction=b>d.currentSlide?"next":"prev"),o&&d.pagingCount===1&&(d.direction=d.currentItem<b?"next":"prev");if(!d.animating&&(d.canAdvance(b,i)||f)&&d.is(":visible")){if(o&&h){var j=a(d.vars.asNavFor).data("flexslider");d.atEnd=b===0||b===d.count-1,j.flexAnimate(b,!0,!1,!0,i),d.direction=d.currentItem<b?"next":"prev",j.direction=d.direction;if(Math.ceil((b+1)/d.visible)-1===d.currentSlide||b===0)return d.currentItem=b,d.slides.removeClass(e+"active-slide").eq(b).addClass(e+"active-slide"),!1;d.currentItem=b,d.slides.removeClass(e+"active-slide").eq(b).addClass(e+"active-slide"),b=Math.floor(b/d.visible)}d.animating=!0,d.animatingTo=b,c&&d.pause(),d.vars.before(d),d.syncExists&&!i&&p.sync("animate"),d.vars.controlNav&&p.controlNav.active(),m||d.slides.removeClass(e+"active-slide").eq(b).addClass(e+"active-slide"),d.atEnd=b===0||b===d.last,d.vars.directionNav&&p.directionNav.update(),b===d.last&&(d.vars.end(d),d.vars.animationLoop||d.pause());if(!n){var q=k?d.slides.filter(":first").height():d.computedW,r,s,t;m?(r=d.vars.itemMargin,t=(d.itemW+r)*d.move*d.animatingTo,s=t>d.limit&&d.visible!==1?d.limit:t):d.currentSlide===0&&b===d.count-1&&d.vars.animationLoop&&d.direction!=="next"?s=l?(d.count+d.cloneOffset)*q:0:d.currentSlide===d.last&&b===0&&d.vars.animationLoop&&d.direction!=="prev"?s=l?0:(d.count+1)*q:s=l?(d.count-1-b+d.cloneOffset)*q:(b+d.cloneOffset)*q,d.setProps(s,"",d.vars.animationSpeed);if(d.transitions){if(!d.vars.animationLoop||!d.atEnd)d.animating=!1,d.currentSlide=d.animatingTo;d.container.unbind("webkitTransitionEnd transitionend"),d.container.bind("webkitTransitionEnd transitionend",function(){d.wrapup(q)})}else d.container.animate(d.args,d.vars.animationSpeed,d.vars.easing,function(){d.wrapup(q)})}else g?(d.slides.eq(d.currentSlide).css({opacity:0,zIndex:1}),d.slides.eq(b).css({opacity:1,zIndex:2}),d.wrapup(q)):(d.slides.eq(d.currentSlide).css({zIndex:1}).animate({opacity:0},d.vars.animationSpeed,d.vars.easing),d.slides.eq(b).css({zIndex:2}).animate({opacity:1},d.vars.animationSpeed,d.vars.easing,d.wrapup));d.vars.smoothHeight&&p.smoothHeight(d.vars.animationSpeed)}},d.wrapup=function(a){!n&&!m&&(d.currentSlide===0&&d.animatingTo===d.last&&d.vars.animationLoop?d.setProps(a,"jumpEnd"):d.currentSlide===d.last&&d.animatingTo===0&&d.vars.animationLoop&&d.setProps(a,"jumpStart")),d.animating=!1,d.currentSlide=d.animatingTo,d.vars.after(d)},d.animateSlides=function(){!d.animating&&q&&d.flexAnimate(d.getTarget("next"))},d.pause=function(){clearInterval(d.animatedSlides),d.animatedSlides=null,d.playing=!1,d.vars.pausePlay&&p.pausePlay.update("play"),d.syncExists&&p.sync("pause")},d.play=function(){d.playing&&clearInterval(d.animatedSlides),d.animatedSlides=d.animatedSlides||setInterval(d.animateSlides,d.vars.slideshowSpeed),d.started=d.playing=!0,d.vars.pausePlay&&p.pausePlay.update("pause"),d.syncExists&&p.sync("play")},d.stop=function(){d.pause(),d.stopped=!0},d.canAdvance=function(a,b){var c=o?d.pagingCount-1:d.last;return b?!0:o&&d.currentItem===d.count-1&&a===0&&d.direction==="prev"?!0:o&&d.currentItem===0&&a===d.pagingCount-1&&d.direction!=="next"?!1:a===d.currentSlide&&!o?!1:d.vars.animationLoop?!0:d.atEnd&&d.currentSlide===0&&a===c&&d.direction!=="next"?!1:d.atEnd&&d.currentSlide===c&&a===0&&d.direction==="next"?!1:!0},d.getTarget=function(a){return d.direction=a,a==="next"?d.currentSlide===d.last?0:d.currentSlide+1:d.currentSlide===0?d.last:d.currentSlide-1},d.setProps=function(a,b,c){var e=function(){var c=a?a:(d.itemW+d.vars.itemMargin)*d.move*d.animatingTo,e=function(){if(m)return b==="setTouch"?a:l&&d.animatingTo===d.last?0:l?d.limit-(d.itemW+d.vars.itemMargin)*d.move*d.animatingTo:d.animatingTo===d.last?d.limit:c;switch(b){case"setTotal":return l?(d.count-1-d.currentSlide+d.cloneOffset)*a:(d.currentSlide+d.cloneOffset)*a;case"setTouch":return l?a:a;case"jumpEnd":return l?a:d.count*a;case"jumpStart":return l?d.count*a:a;default:return a}}();return e*-1+"px"}();d.transitions&&(e=k?"translate3d(0,"+e+",0)":"translate3d("+e+",0,0)",c=c!==undefined?c/1e3+"s":"0s",d.container.css("-"+d.pfx+"-transition-duration",c)),d.args[d.prop]=e,(d.transitions||c===undefined)&&d.container.css(d.args)},d.setup=function(b){if(!n){var c,f;b==="init"&&(d.viewport=a('<div class="'+e+'viewport"></div>').css({overflow:"hidden",position:"relative"}).appendTo(d).append(d.container),d.cloneCount=0,d.cloneOffset=0,l&&(f=a.makeArray(d.slides).reverse(),d.slides=a(f),d.container.empty().append(d.slides))),d.vars.animationLoop&&!m&&(d.cloneCount=2,d.cloneOffset=1,b!=="init"&&d.container.find(".clone").remove(),d.container.append(d.slides.first().clone().addClass("clone").attr("aria-hidden","true")).prepend(d.slides.last().clone().addClass("clone").attr("aria-hidden","true"))),d.newSlides=a(d.vars.selector,d),c=l?d.count-1-d.currentSlide+d.cloneOffset:d.currentSlide+d.cloneOffset,k&&!m?(d.container.height((d.count+d.cloneCount)*200+"%").css("position","absolute").width("100%"),setTimeout(function(){d.newSlides.css({display:"block"}),d.doMath(),d.viewport.height(d.h),d.setProps(c*d.h,"init")},b==="init"?100:0)):(d.container.width((d.count+d.cloneCount)*200+"%"),d.setProps(c*d.computedW,"init"),setTimeout(function(){d.doMath(),d.newSlides.css({width:d.computedW,"float":"left",display:"block"}),d.vars.smoothHeight&&p.smoothHeight()},b==="init"?100:0))}else d.slides.css({width:"100%","float":"left",marginRight:"-100%",position:"relative"}),b==="init"&&(g?d.slides.css({opacity:0,display:"block",webkitTransition:"opacity "+d.vars.animationSpeed/1e3+"s ease",zIndex:1}).eq(d.currentSlide).css({opacity:1,zIndex:2}):d.slides.css({opacity:0,display:"block",zIndex:1}).eq(d.currentSlide).css({zIndex:2}).animate({opacity:1},d.vars.animationSpeed,d.vars.easing)),d.vars.smoothHeight&&p.smoothHeight();m||d.slides.removeClass(e+"active-slide").eq(d.currentSlide).addClass(e+"active-slide")},d.doMath=function(){var a=d.slides.first(),b=d.vars.itemMargin,c=d.vars.minItems,e=d.vars.maxItems;d.w=d.viewport===undefined?d.width():d.viewport.width(),d.h=a.height(),d.boxPadding=a.outerWidth()-a.width(),m?(d.itemT=d.vars.itemWidth+b,d.minW=c?c*d.itemT:d.w,d.maxW=e?e*d.itemT-b:d.w,d.itemW=d.minW>d.w?(d.w-b*(c-1))/c:d.maxW<d.w?(d.w-b*(e-1))/e:d.vars.itemWidth>d.w?d.w:d.vars.itemWidth,d.visible=Math.floor(d.w/d.itemW),d.move=d.vars.move>0&&d.vars.move<d.visible?d.vars.move:d.visible,d.pagingCount=Math.ceil((d.count-d.visible)/d.move+1),d.last=d.pagingCount-1,d.limit=d.pagingCount===1?0:d.vars.itemWidth>d.w?d.itemW*(d.count-1)+b*(d.count-1):(d.itemW+b)*d.count-d.w-b):(d.itemW=d.w,d.pagingCount=d.count,d.last=d.count-1),d.computedW=d.itemW-d.boxPadding},d.update=function(a,b){d.doMath(),m||(a<d.currentSlide?d.currentSlide+=1:a<=d.currentSlide&&a!==0&&(d.currentSlide-=1),d.animatingTo=d.currentSlide);if(d.vars.controlNav&&!d.manualControls)if(b==="add"&&!m||d.pagingCount>d.controlNav.length)p.controlNav.update("add");else if(b==="remove"&&!m||d.pagingCount<d.controlNav.length)m&&d.currentSlide>d.last&&(d.currentSlide-=1,d.animatingTo-=1),p.controlNav.update("remove",d.last);d.vars.directionNav&&p.directionNav.update()},d.addSlide=function(b,c){var e=a(b);d.count+=1,d.last=d.count-1,k&&l?c!==undefined?d.slides.eq(d.count-c).after(e):d.container.prepend(e):c!==undefined?d.slides.eq(c).before(e):d.container.append(e),d.update(c,"add"),d.slides=a(d.vars.selector+":not(.clone)",d),d.setup(),d.vars.added(d)},d.removeSlide=function(b){var c=isNaN(b)?d.slides.index(a(b)):b;d.count-=1,d.last=d.count-1,isNaN(b)?a(b,d.slides).remove():k&&l?d.slides.eq(d.last).remove():d.slides.eq(b).remove(),d.doMath(),d.update(c,"remove"),d.slides=a(d.vars.selector+":not(.clone)",d),d.setup(),d.vars.removed(d)},p.init()},a(window).blur(function(a){focused=!1}).focus(function(a){focused=!0}),a.flexslider.defaults={namespace:"flex-",selector:".slides > li",animation:"fade",easing:"swing",direction:"horizontal",reverse:!1,animationLoop:!0,smoothHeight:!1,startAt:0,slideshow:!0,slideshowSpeed:7e3,animationSpeed:600,initDelay:0,randomize:!1,thumbCaptions:!1,pauseOnAction:!0,pauseOnHover:!1,pauseInvisible:!0,useCSS:!0,touch:!0,video:!1,controlNav:!0,directionNav:!0,prevText:"Previous",nextText:"Next",keyboard:!0,multipleKeyboard:!1,mousewheel:!1,pausePlay:!1,pauseText:"Pause",playText:"Play",controlsContainer:"",manualControls:"",sync:"",asNavFor:"",itemWidth:0,itemMargin:0,minItems:1,maxItems:0,move:0,allowOneSlide:!0,start:function(){},before:function(){},after:function(){},end:function(){},added:function(){},removed:function(){}},a.fn.flexslider=function(b){b===undefined&&(b={});if(typeof b=="object")return this.each(function(){var c=a(this),d=b.selector?b.selector:".slides > li",e=c.find(d);e.length===1&&b.allowOneSlide===!0||e.length===0?(e.fadeIn(400),b.start&&b.start(c)):c.data("flexslider")===undefined&&new a.flexslider(this,b)});var c=a(this).data("flexslider");switch(b){case"play":c.play();break;case"pause":c.pause();break;case"stop":c.stop();break;case"next":c.flexAnimate(c.getTarget("next"),!0);break;case"prev":case"previous":c.flexAnimate(c.getTarget("prev"),!0);break;default:typeof b=="number"&&c.flexAnimate(b,!0)}}}(window.hsjQuery||jQuery),function(){var a;a=function(a){var b,c;return b=!1,a(function(){var d;return d=(document.body||document.documentElement).style,b=d.animation!==void 0||d.WebkitAnimation!==void 0||d.MozAnimation!==void 0||d.MsAnimation!==void 0||d.OAnimation!==void 0,a(window).bind("keyup.vex",function(a){if(a.keyCode===27)return c.closeByEscape()})}),c={globalID:1,animationEndEvent:"animationend webkitAnimationEnd mozAnimationEnd MSAnimationEnd oanimationend",baseClassNames:{vex:"vex",content:"vex-content",overlay:"vex-overlay",close:"vex-close",closing:"vex-closing",open:"vex-open"},defaultOptions:{content:"",showCloseButton:!0,escapeButtonCloses:!0,overlayClosesOnClick:!0,appendLocation:"body",className:"",css:{},overlayClassName:"",overlayCSS:{},contentClassName:"",contentCSS:{},closeClassName:"",closeCSS:{}},open:function(b){return b=a.extend({},c.defaultOptions,b),b.id=c.globalID,c.globalID+=1,b.$vex=a("<div>").addClass(c.baseClassNames.vex).addClass(b.className).css(b.css).data({vex:b}),b.$vexOverlay=a("<div>").addClass(c.baseClassNames.overlay).addClass(b.overlayClassName).css(b.overlayCSS).data({vex:b}),b.overlayClosesOnClick&&b.$vexOverlay.bind("click.vex",function(b){if(b.target!==this)return;return c.close(a(this).data().vex.id)}),b.$vex.append(b.$vexOverlay),b.$vexContent=a("<div>").addClass(c.baseClassNames.content).addClass(b.contentClassName).css(b.contentCSS).append(b.content).data({vex:b}),b.$vex.append(b.$vexContent),b.showCloseButton&&(b.$closeButton=a("<div>").addClass(c.baseClassNames.close).addClass(b.closeClassName).css(b.closeCSS).data({vex:b}).bind("click.vex",function(){return c.close(a(this).data().vex.id)}),b.$vexContent.append(b.$closeButton)),a(b.appendLocation).append(b.$vex),c.setupBodyClassName(b.$vex),b.afterOpen&&b.afterOpen(b.$vexContent,b),setTimeout(function(){return b.$vexContent.trigger("vexOpen",b)},0),b.$vexContent},getAllVexes:function(){return a("."+c.baseClassNames.vex+':not(".'+c.baseClassNames.closing+'") .'+c.baseClassNames.content)},getVexByID:function(b){return c.getAllVexes().filter(function(){return a(this).data().vex.id===b})},close:function(a){var b;if(!a){b=c.getAllVexes().last();if(!b.length)return!1;a=b.data().vex.id}return c.closeByID(a)},closeAll:function(){var b;return b=c.getAllVexes().map(function(){return a(this).data().vex.id}).toArray(),(b!=null?!b.length:!void 0)?!1:(a.each(b.reverse(),function(a,b){return c.closeByID(b)}),!0)},closeByID:function(d){var e,f,g,h,i;f=c.getVexByID(d);if(!f.length)return;return e=f.data().vex.$vex,i=a.extend({},f.data().vex),g=function(){if(i.beforeClose)return i.beforeClose(f,i)},h=function(){f.trigger("vexClose",i),e.remove();if(i.afterClose)return i.afterClose(f,i)},b?(g(),e.unbind(c.animationEndEvent).bind(c.animationEndEvent,function(){return h()}).addClass(c.baseClassNames.closing)):(g(),h()),!0},closeByEscape:function(){var b,d,e;return e=c.getAllVexes().map(function(){return a(this).data().vex.id}).toArray(),(e!=null?!e.length:!void 0)?!1:(d=Math.max.apply(Math,e),b=c.getVexByID(d),b.data().vex.escapeButtonCloses!==!0?!1:c.closeByID(d))},setupBodyClassName:function(b){return b.bind("vexOpen.vex",function(){return a("body").addClass(c.baseClassNames.open)}).bind("vexClose.vex",function(){if(!c.getAllVexes().length)return a("body").removeClass(c.baseClassNames.open)})},hideLoading:function(){return a(".vex-loading-spinner").remove()},showLoading:function(){return c.hideLoading(),a("body").append('<div class="vex-loading-spinner '+c.defaultOptions.className+'"></div>')}}},window.vex=a(typeof hsjQuery!="undefined"&&hsjQuery!==null?hsjQuery:jQuery)}.call(this),function(){var a,b,c,d;a=typeof hsjQuery!="undefined"&&hsjQuery!==null?hsjQuery:jQuery,a.fn.nextWrap=function(){var a;return a=this.next(),a.length===0?this.siblings().first():a},a.fn.prevWrap=function(){var a;return a=this.prev(),a.length===0?this.siblings().last():a},a.loadImage=function(b){var c;return c=function(a){var c,d,e,f;e=function(){f(),a.resolve(d)},c=function(){f(),a.reject(d)},f=function(){d.onload=null,d.onerror=null,d.onabort=null},d=new Image,d.onload=e,d.onerror=c,d.onabort=c,d.src=b},a.Deferred(c).promise()},c={x:1e3,y:600},window.hsInitSlider=d=function(){if(window.hsSliderConfig)return a("html").removeClass("no-js"),a.each(window.hsSliderConfig,b)},b=function(b,d){var e,f,g,h,i,j,k,l,m,n,o,p,q;return h=a("#hs_cos_flex_slider_control_panel_"+b),f=a("#hs_cos_flex_slider_"+b),i=null,j=null,l=null,m=function(){return j=f.clone(),a(window).resize(q)},n=function(b){if(!b.attr("data-src"))return;return a.loadImage(b.data("src")).done(function(){return b.attr("src",b.data("src")),b.removeAttr("data-src")})},o=function(b){var c,e;return c=function(b){var c,d;c=a(b.slides.get(b.animatingTo)).find("img");if(!c.data("naturalWidth")||!c.data("naturalHeight"))d=new Image,d.src=c.attr("src"),c.data("naturalWidth",d.width),c.data("naturalHeight",d.height);return q({x:c.data("naturalWidth"),y:c.data("naturalHeight")})},i=vex.open({content:j,contentClassName:"hs-gallery",overlayClassName:"hs-gallery"}),e=a.extend(d.mainConfig,{before:c,after:function(a){return a.resize()},startAt:b,keyboard:!0,multipleKeyboard:!0}),window.gallerySlider=j.flexslider(e),l=j.data("flexslider"),c(l)},q=function(b){var d,e,f,g,h,j,k;if(b&&b.currentTarget)return;return a.isPlainObject(b)?(f=b.x/b.y,k=a(window).width()/a(window).height(),d=b,e={x:a(window).width()-20,y:a(window).height()-20},f<k?b.y>e.y&&(h=e.y/b.y,d.x=b.x*h,d.y=e.y):b.x>e.x&&(g=e.x/b.x,d.y=b.y*g,d.x=e.x),j={x:Math.max(a(window).width()-d.x,0),y:Math.max(a(window).height()-d.y,0)}):j={x:Math.max(a(window).width()-c.x,20),y:Math.max(a(window).height()-c.y,20)},i.css({left:j.x/2,top:j.y/2,bottom:j.y/2,right:j.x/2}),i.find(".hs_cos_flex-slides li").width(d.x+"px"),setTimeout(function(){return l.resize()},100)},p=function(b){return b.each(function(b,c){return new Image(a(c).attr("src"))})},k=function(b){var c,e,f,g;return c=a(b),c.hasClass("hs-cos-flex-slider-control-panel")?g=".hs_cos_flex-slides > li > a > img":g=".hs_cos_flex-slides > li > img",e=[],c.find(g).each(function(){return e.push(a(this).height())}),f=Math.min.apply(Math,e),d.mainConfig.smoothHeight||c.find(".hs_cos_flex-viewport").height(f),c.find(g).each(function(){var b;return b=a(this).width()/a(this).height(),a(this).width(f*b)})},d.mode==="lightbox"?(d.mainConfig.sync=null,h.find("li").show().each(function(){return a(this).find("a").click(function(){var b;return b=a(this).parent().index(),m(),o(b),!1})}),e=f.find("img"),p(e)):(d.thumbConfig&&(g=h.find(".hs_cos_flex-slides-thumb > li"),a.extend(d.thumbConfig,{itemWidth:g.length&&g.width()?g.width():d.thumbConfig.itemWidth,start:k}),h.flexslider(d.thumbConfig)),a(".hs_cos_flex-slides-main img[data-src]")?(a.extend(d.mainConfig,{start:d.thumbConfig?k:{},before:function(a){var b,c;return c=f.find(".hs_cos_flex-active-slide").prevWrap().find("img"),n(c),b=f.find(".hs_cos_flex-active-slide").nextWrap().find("img"),n(b)}}),a.when(n(f.find("img:eq(0)")),n(f.find("img:eq(1)")),n(f.find("img").last())).then(function(){return f.flexslider(d.mainConfig)})):f.flexslider(d.mainConfig))},a(window).bind("load hs:previewLoad",function(){try{return d()}catch(a){if(console&&typeof console.log=="function")return console.log(a)}})}.call(this),function(a){function c(c){function e(b,c){var d=a("<div></div>");c?d.addClass("hs-common-error-message"):d.addClass("hs-common-confirm-message"),d.html(b),a("form#blog-comment-form").prepend(d)}function f(b){var c=a("<div></div>");c.addClass("confirm-message"),c.html(b),a("form#blog-comment-form")}function g(a){var b,c,e,f,g;b=hsVars.ticks+"-"+hsVars.page_id,c=[];for(var h=0;h<b.length;h++)e=b.charCodeAt(h),f=d[a].charCodeAt(h),g=e-96,g>126&&(g-=126),g+=49,c.push(String.fromCharCode(g));return c.join("")}function h(){var b=[];return a("#id_user_name").val()||b.push("Name is required"),a("#id_user_email").val()?a("#id_user_email").val().indexOf("@")==-1&&b.push("Email address is not valid"):b.push("Email is required"),a("#id_comment").val()||b.push("Comment is required"),i(b)}function i(a){return a.length>0?(a.unshift("One or more errors occurred:"),e(a.join("<br/>&bull; "),!0),!1):!0}function j(a){var b,c=[],d=["comment","user_name","user_email","user_website"];a.recaptcha_response_field&&(c.push("Enter a valid captcha response."),delete a.recaptcha_response_field);for(var e=0;e<d.length;e++)b=d[e],a.hasOwnProperty(b)&&c.push(a[b][0]);return c.length>0&&window.Recaptcha&&Recaptcha.reload(),i(c)}a("form#blog-comment-form .hs-common-error-message").remove(),a("form#blog-comment-form .hs-common-confirm-message").remove();var d={a:"bZVI3LbCjMC5ATa0Xe6u5lHhnp846imYJaUEBsNS1osqQoMvEpuaW8BqUjkmOnbH5MjQqZDrWtbhJrAq",b:"sNYWQs1vIh842hn9i7uUN3SY0ku2l22xtaSYledfPc30n2d4FOjSOL8zx7P6P7389qqW0jfrm3ge3yWH",c:"BsqFip3YGP2NfbWKePmqmWaLgf4TPlsLaAC2MoFLo6ZzwB17Z8GNxaWrxDBMkSISQQwZ7sN07B2yYao7"};return c.preventDefault(),c.stopPropagation(),b.isSaving?!1:h()?(b.isSaving=!0,a('form#blog-comment-form input[type="submit"]').val("Saving..."),data=a("form#blog-comment-form").serialize(),data+="&anti_spam_key="+g("a"),data+="&key_check_"+g("b")+"="+g("c"),a.ajax(a("form#blog-comment-form").attr("action"),{data:data,dataType:"json",type:"POST",error:function(c){a('form#blog-comment-form input[type="submit"]').val("Submit"),e(c.message,!0),b.isSaving=!1},success:function(c){a('form#blog-comment-form input[type="submit"]').val("Submit"),c.succeeded?(e(c.message+'<span id="hs-added-comment-id" style="display:none">'+
c.comment_id+"</span>",!1),b.isSaving=!1,a("input#add-comment-button").addClass("hidden"),a("form#blog-comment-form .field").hide("slow")):(j(c.error_dict),b.isSaving=!1)}}),!1):!1}function d(){a("form#blog-comment-form").not(".new-comments").submit(c)}var b={isSaving:!1};a(document).ready(d)}(jQuery),function(a){function b(b){a(this).prev("ul").children("li").show(),a(this).hide(),b.preventDefault(),b.stopPropagation()}function c(){a(".filter-expand-link").click(b),window.hs_show_tools_menu_if_author();var c=function(b,c){b.find(".hs-classic-form-errors")&&b.find(".hs-classic-form-errors").remove(),$errors=a('<div class="hs-classic-form-errors message">'),$errors.append('<div class="top-message">Error submitting form</div>'),a(c).each(function(b,c){var d;switch(c.error){case"required":d='Field "'+c.field.label+'" is required';break;case"email_invalid":d='Invalid email address in "'+c.field.name+'" (will be kept private, of course)'}$errors.append(a('<div class="ValidationErrorMessage">').html(d))}),b.prepend($errors)},d=/^(([^<>()\[\]\\.,;:\s@\"]+(\.[^<>()\[\]\\.,;:\s@\"]+)*)|(\".+\"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/;a("form[data-hs-classic-form-key]").submit(function(){if(!window.hsClassicFormSchema)return!0;var b=a(this),e=[],f=window.hsClassicFormSchema[b.data("hs-classic-form-key")];b.find("input").each(function(){var b=a(this),c=a(this).attr("name").split(":")[1],g,h;g=a.grep(f,function(a){return a.name==c});if(!g.length)return;h=g[0],h.required&&(b.val()||e.push({field:h,error:"required"})),h.name.toLowerCase()=="email"&&(d.test(b.val())||e.push({field:h,error:"email_invalid"}))});if(e.length)return c(b,e),!1})}a(document).ready(c)}(jQuery),function(){var a;(a=window.hubspot)==null&&(window.hubspot={}),function(a,b){var c,d,e;return d=2,c=function(a,b){var c,d;return c=function(){var a;if(b&&!b.done)return window.hsEmbedComments!=null&&((a=window.hbspt)!=null?a.forms:void 0)!=null?(b.done=!0,b()):setTimeout(c,50)},d=document.createElement("script"),d.type="text/"+(a.type||"javascript"),d.src=a.src||a,d.async=!1,d.onreadystatechange=d.onload=c,(document.body||document.head).appendChild(d)},e=[{local:"http://js.hubspotqa.com/forms/current.js",qa:"http://js.hubspotqa.com/forms/current.js",prod:"http://js.hubspot.com/forms/current.js"},{local:"http://local.hubspotqa.com:3333/comments_embed/static-2.141/bundles/project.js",qa:"https://static.hsstatic.net/comments_embed/ex/embed-qa.js",prod:"https://static.hsstatic.net/comments_embed/ex/embed.js"}],b.exports.loadCommentsEmbed=function(a,b){var d,f,g,h;c("https://www.google.com/recaptcha/api/js/recaptcha_ajax.js"),h=[];for(f=0,g=e.length;f<g;f++)d=e[f],h.push(c(d[a],b));return h}}(jQuery,{exports:window.hubspot})}.call(this);