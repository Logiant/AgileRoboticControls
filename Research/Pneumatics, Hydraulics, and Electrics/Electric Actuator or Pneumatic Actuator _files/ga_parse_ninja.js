/**
 *  @author:    Danny Ng (http://www.dannytalk.com/read-google-analytics-cookie-script/)
 *  @modified:  19/08/10
 *  @notes:     Free to use and distribute without altering this comment. Would appreciate a link back :)
 *
 *  Modifications by Analytics Ninja
 */

window._gaq = window._gaq || [];
 
// Strip leading and trailing white-space
String.prototype.trim = function() { return this.replace(/^\s*|\s*$/g, ''); };
 
// Check if string is empty
String.prototype.empty = function() {
    if (this.length === 0)
        return true;
    else if (this.length > 0)
        return (/^\s*$/).test(this);
    else
        return true;
};
 

/**
 *  For GA cookie explanation, see http://services.google.com/analytics/breeze/en/ga_cookies/index.html.
 *
 *  @return             -   <void>
 *
 *  @pre-condition      -   pageTracker initialised properly
 *  @post-condition     -   provides 'get' methods to access specific values in the Google Analytics cookies
 */
function GaCookiesNinja(cookie_override) {
    
    var the_cookie = cookie_override || document.cookie;
    
    // Breaks cookie into an object of keypair cookie values
    function crumbleCookie(c)
    {
        var cookie_array = the_cookie.split(';');
        var keyvaluepair = {};
        for (var cookie = 0; cookie < cookie_array.length; cookie++)
        {
            var key = cookie_array[cookie].substring(0, cookie_array[cookie].indexOf('=')).trim();
            var value = cookie_array[cookie].substring(cookie_array[cookie].indexOf('=')+1, cookie_array[cookie].length).trim();
            keyvaluepair[key] = value;
        }
     
        if (c)
            return keyvaluepair[c] ? keyvaluepair[c] : null;
     
        return keyvaluepair;
    }   

    
    // Cookie syntax: domain-hash.unique-id.ftime.ltime.stime.session-counter
    var utma = function() {
        var utma_array;
 
        if (crumbleCookie('__utma'))
            utma_array =  crumbleCookie('__utma').split('.');
        else
            return null;
 
        var domainhash = utma_array[0];
        var uniqueid = utma_array[1];
        var ftime = utma_array[2];
        var ltime = utma_array[3];
        var stime = utma_array[4];
        var sessions = utma_array[5];
 
        return {
            'cookie': utma_array,
            'domainhash': domainhash,
            'uniqueid': uniqueid,
            'ftime': ftime,
            'ltime': ltime,
            'stime': stime,
            'sessions': sessions
        };
    };
 
    // Cookie syntax: domain-hash.gif-requests.10.stime
    var utmb = function() {
        var utmb_array;
 
        if (crumbleCookie('__utmb'))
            utmb_array = crumbleCookie('__utmb').split('.');
        else
            return null;
        var gifrequest = utmb_array[1];
 
        return {
            'cookie': utmb_array,
            'gifrequest': gifrequest
        };
    };
 
    // Cookie syntax: domain-hash.value
    var utmv = function() {
        var utmv_array;
 
        if (crumbleCookie('__utmv'))
            utmv_array = crumbleCookie('__utmv').split('.');
        else
            return null;
 
        var value = utmv_array[1];
 
        return {
            'cookie': utmv_array,
            'value': value
        };
    };
 
    // Cookie syntax: domain-hash.ftime.?.?.utmcsr=X|utmccn=X|utmcmd=X|utmctr=X
    var utmz = function() {
        var utmz_array, source, medium, name, term, content, gclid;
 
        if (crumbleCookie('__utmz'))
            utmz_array = crumbleCookie('__utmz').split('.');
        else
            return null;
 
        var utms = utmz_array[4].split('|');
        for (var i = 0; i < utms.length; i++) {
            var key = utms[i].substring(0, utms[i].indexOf('='));
            var val = decodeURIComponent(utms[i].substring(utms[i].indexOf('=')+1, utms[i].length));
            val = val.replace(/^\(|\)$/g, '');  // strip () brackets
            switch(key)
            {
                case 'utmcsr':
                    source = val;
                    break;
                case 'utmcmd':
                    medium = val;
                    break;
                case 'utmccn':
                    name = val;
                    break;
                case 'utmctr':
                    term = val;
                    break;
                case 'utmcct':
                    content = val;
                    break;
                case 'utmgclid':
                    gclid = val;
                    break;
            }
        }
 
        return {
            'cookie': utmz_array,
            'source': source,
            'medium': medium,
            'name': name,
            'term': term,
            'content': content,
            'gclid': gclid
        };
    };
 
    // Establish public methods
 
    // utma cookies
    this.getDomainHash = function() { return (utma() && utma().domainhash) ? utma().domainhash : null; };
    this.getUniqueId = function() { return (utma() && utma().uniqueid) ? utma().uniqueid : null; };
 
    this.getInitialVisitTime = function() { return (utma() && utma().ftime) ? utma().ftime : null; };
    this.getPreviousVisitTime = function() { return (utma() && utma().ltime) ? utma().ltime : null; };
    this.getCurrentVisitTime = function() { return (utma() && utma().stime) ? utma().stime : null; };
    this.getSessionCounter = function() { return (utma() && utma().sessions) ? utma().sessions : null; };
 
    // utmb cookies
    this.getGifRequests = function() { return (utmb() && utmb().gifrequest) ? utmb().gifrequest : null; };
 
    // utmv cookies
    this.getUserDefinedValue = function () { return (utmv() && utmv().value) ? decodeURIComponent(utmv().value) : null; };
 
    // utmz cookies
    this.getCampaignSource = function () { return (utmz() && utmz().source) ? utmz().source : null; };
    this.getCampaignMedium = function () { return (utmz() && utmz().medium) ? utmz().medium : null; };
    this.getCampaignName = function () { return (utmz() && utmz().name) ? utmz().name : null; };
    this.getCampaignTerm = function () { return (utmz() && utmz().term) ? utmz().term : null; };
    this.getCampaignContent = function () { return (utmz() && utmz().content) ? utmz().content : null; };
    this.getGclid = function () { return (utmz() && utmz().gclid) ? utmz().gclid : null; };
    
    
    
    //helper function to return commonly used values by Analytics Ninja
    this.ninjaValues = function(){
        
        var uniqueid = this.getUniqueId();
        var gasource = this.getCampaignSource();
        var gamedium = this.getCampaignMedium();
        var gaterm = this.getCampaignTerm();
        var gacampaign = this.getCampaignName();
        var gacontent = this.getCampaignContent();

        var gclid = this.getGclid();
        if (gclid !== null) {
            gasource = 'google';
            gamedium = 'cpc';
        }        

        var firstVisitTime = this.getInitialVisitTime(),
            firstSourceMedium, firstCampaignKeyword, FT,firstVisitString;

        if (this.getSessionCounter() == 1) {
            firstSourceMedium = [gasource,gamedium].join(':');
            firstCampaignKeyword = [gacampaign,gaterm].join(':');
            FT = [gasource,gamedium,gaterm,gacampaign,gacontent].join('|');
        }
        
        if (firstVisitTime) {
            
            var d = new Date(firstVisitTime * 1000);
            var pad = function(number) {
                var r = String(number);
                if (r.length === 1) {
                    r = '0' + r;
                }
                return r;
            };

            //YYYY-MM-DD
            firstVisitString = [d.getUTCFullYear(),pad(d.getUTCMonth() + 1),pad(d.getUTCDate())].join('-');

        } else {
            firstVisitString = '';
        }        
        
        this.ninja = {
            uniqueid: uniqueid,
            source: gasource,
            medium: gamedium,
            campaign: gacampaign,
            term: gaterm,
            content: gacontent,
            gclid: gclid,
            firstVisitTime: firstVisitTime,
            firstVisitString: firstVisitString,
            firstSourceMedium: firstSourceMedium,
            firstCampaignKeyword: firstCampaignKeyword,
            FT: FT
        };
        
        
    };
    
    //run the ninjavalues function when first initialized
    this.ninjaValues();

}