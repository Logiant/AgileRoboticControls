if (typeof SwfHelper == "undefined") {
    function SwfHelper(modernizr, swfObject) {

        var _modernizr = modernizr || Modernizr;
        var _swfObject = swfObject || swfobject;

        function generateNewId() {
            return 'xxxxxxxx-xxxx-4xxx-yxxx-xxxxxxxxxxxx'.replace(/[xy]/g, function (c) {
                var r = Math.random() * 16 | 0, v = c == 'x' ? r : (r & 0x3 | 0x8);
                return v.toString(16);
            });
        };

        function removeElement(element) {
            if (element && element.parentNode)
                element.parentNode.removeChild(element);
        }

        var _public = {
            "embed": function (element) {

                if (_modernizr.canvas && _public.htmlPath) {
                    // HTML5 support, use it

                    removeElement(element);

                    document.write("<iframe src='" + _public.htmlPath + "' ></iframe>");
                }
                else if (_swfObject.hasFlashPlayerVersion("9.0.0") && _public.swfPath) {
                    // Flash is supported, use it

                    var id = element.id;

                    if (!id || document.getElementById(id)) {
                        id = "SwiffyLearningObject_" + generateNewId();
                    }

                    element.id = id;

                    if (!_public.flashvars)
                        _public.flashvars = {};

                    if (!_public.attributes)
                        _public.attributes = {};

                    if (!_public.params)
                        _public.params = {};

                    _swfObject.embedSWF(_public.swfPath, id, _public.width, _public.height, _public.version, _public.expressInstall, _public.flashvars, _public.params, _public.attributes);
                }
                else {
                    // No Html5 and no Flash??  Well, they're not going to have a fun time.
                }
            },
            "attributes": {},
            "params": {},
            "flashvars": {},
            "width": 800,
            "height": 600,
            "version": "9.0.0",
            "expressInstall": "expressInstall.swf"
        };

        return _public;
    }
}