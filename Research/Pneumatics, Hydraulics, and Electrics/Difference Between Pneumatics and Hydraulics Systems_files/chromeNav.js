var cssdropdown={disappeardelay:250,dropdownindicator:'<img src="http://www.alteredgamer.com/_static/images/icon_down.gif" border="0" />',enablereveal:[true,5],enableiframeshim:1,dropmenuobj:null,asscmenuitem:null,domsupport:document.all||document.getElementById,standardbody:null,iframeshimadded:false,revealtimers:{},getposOffset:function(d,a){var c=(a=="left")?d.offsetLeft:d.offsetTop;var b=d.offsetParent;while(b!=null){c=(a=="left")?c+b.offsetLeft:c+b.offsetTop;b=b.offsetParent}return c},css:function(b,d,a){var c=new RegExp("(^|\\s+)"+d+"($|\\s+)","ig");if(a=="check"){return c.test(b.className)}else{if(a=="remove"){b.className=b.className.replace(c,"")}else{if(a=="add"&&!c.test(b.className)){b.className+=" "+d}}}},showmenu:function(a,b){if(this.enablereveal[0]){if(!a._trueheight||a._trueheight<10){a._trueheight=a.offsetHeight}clearTimeout(this.revealtimers[a.id]);a.style.height=a._curheight=0;a.style.overflow="hidden";a.style.visibility="visible";this.revealtimers[a.id]=setInterval(function(){cssdropdown.revealmenu(a)},10)}else{a.style.visibility="visible"}this.css(this.asscmenuitem,"selected","add")},revealmenu:function(c,b){var a=c._curheight,d=c._trueheight,f=this.enablereveal[1];if(a<d){var e=Math.min(a,d);c.style.height=e+"px";c._curheight=e+Math.round((d-e)/f)+1}else{c.style.height="auto";c.style.overflow="hidden";clearInterval(this.revealtimers[c.id])}},clearbrowseredge:function(d,f){var c=0;if(f=="rightedge"){var g=document.all&&!window.opera?this.standardbody.scrollLeft+this.standardbody.clientWidth-15:window.pageXOffset+window.innerWidth-15;var b=this.dropmenuobj.offsetWidth;if(g-this.dropmenuobj.x<b){c=b-d.offsetWidth}}else{var e=document.all&&!window.opera?this.standardbody.scrollTop:window.pageYOffset;var g=document.all&&!window.opera?this.standardbody.scrollTop+this.standardbody.clientHeight-15:window.pageYOffset+window.innerHeight-18;var a=this.dropmenuobj._trueheight;if(g-this.dropmenuobj.y<a){c=a+d.offsetHeight;if((this.dropmenuobj.y-e)<a){c=this.dropmenuobj.y+d.offsetHeight-e}}}return c},dropit:function(c,b,a){if(this.dropmenuobj!=null){this.hidemenu()}this.clearhidemenu();this.dropmenuobj=document.getElementById(a);this.asscmenuitem=c;this.showmenu(this.dropmenuobj,b);this.dropmenuobj.x=this.getposOffset(c,"left");this.dropmenuobj.y=this.getposOffset(c,"top");this.dropmenuobj.style.left=this.dropmenuobj.x-this.clearbrowseredge(c,"rightedge")+"px";this.dropmenuobj.style.top=this.dropmenuobj.y-this.clearbrowseredge(c,"bottomedge")+c.offsetHeight+1+"px";this.positionshim()},positionshim:function(){if(this.iframeshimadded){if(this.dropmenuobj.style.visibility=="visible"){this.shimobject.style.width=this.dropmenuobj.offsetWidth+"px";this.shimobject.style.height=this.dropmenuobj._trueheight+"px";this.shimobject.style.left=parseInt(this.dropmenuobj.style.left)+"px";this.shimobject.style.top=parseInt(this.dropmenuobj.style.top)+"px";this.shimobject.style.display="block"}}},hideshim:function(){if(this.iframeshimadded){this.shimobject.style.display="none"}},isContained:function(d,b){var b=window.event||b;var a=b.relatedTarget||((b.type=="mouseover")?b.fromElement:b.toElement);while(a&&a!=d){try{a=a.parentNode}catch(b){a=d}}if(a==d){return true}else{return false}},dynamichide:function(b,a){if(!this.isContained(b,a)){this.delayhidemenu()}},delayhidemenu:function(){this.delayhide=setTimeout("cssdropdown.hidemenu()",this.disappeardelay)},hidemenu:function(){this.css(this.asscmenuitem,"selected","remove");this.dropmenuobj.style.visibility="hidden";this.dropmenuobj.style.left=this.dropmenuobj.style.top="-1000px";this.hideshim()},clearhidemenu:function(){if(this.delayhide!="undefined"){clearTimeout(this.delayhide)}},addEvent:function(b,a,c){if(b.addEventListener){b.addEventListener(c,a,false)}else{if(b.attachEvent){b.attachEvent("on"+c,function(){return a.call(b,window.event)})}}},startchrome:function(){if(!this.domsupport){return}this.standardbody=(document.compatMode=="CSS1Compat")?document.documentElement:document.body;for(var d=0;d<arguments.length;d++){var f=document.getElementById(arguments[d]).getElementsByTagName("a");for(var c=0;c<f.length;c++){if(f[c].getAttribute("rel")){var g=f[c].getAttribute("rel");var a=document.getElementById(g);this.addEvent(a,function(){cssdropdown.clearhidemenu()},"mouseover");this.addEvent(a,function(h){cssdropdown.dynamichide(this,h)},"mouseout");this.addEvent(a,function(){cssdropdown.delayhidemenu()},"click");try{f[c].innerHTML=f[c].innerHTML+" "+this.dropdownindicator}catch(b){}this.addEvent(f[c],function(h){if(!cssdropdown.isContained(this,h)){var i=window.event||h;cssdropdown.dropit(this,i,this.getAttribute("rel"))}},"mouseover");this.addEvent(f[c],function(h){cssdropdown.dynamichide(this,h)},"mouseout");this.addEvent(f[c],function(){cssdropdown.delayhidemenu()},"click")}}}if(this.enableiframeshim&&document.all&&!window.XDomainRequest&&!this.iframeshimadded){document.write('<IFRAME id="iframeshim" src="about:blank" frameBorder="0" scrolling="no" style="left:0; top:0; position:absolute; display:none;z-index:90; background: transparent;"></IFRAME>');this.shimobject=document.getElementById("iframeshim");this.shimobject.style.filter="progid:DXImageTransform.Microsoft.Alpha(style=0,opacity=0)";this.iframeshimadded=true}}};