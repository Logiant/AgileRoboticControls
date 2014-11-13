var SetupFocusOnCollapsible = function () {
    $('.entityNewDiscussionCollapsible, .entityNewQuestionCommentCollapsible, .entityNewAnswerCommentCollapsible, .entityAnswerThisQuestionCollapsible, .entityNewQuestionCollapsible, .entityAnswerCommentsCollapsible, .replyCommentButtonCollapsible')
        .on('shown.bs.collapse', function () {
            $(this).find(".newCommentText").focus();
        });
};
$(function () {
    function IsUserLoggedIn() {
        if ($(".entityLoginData").data("loggedin") == "True") {
            return true;
        }

        if ($(".learningObjectLoginData").data("loggedin") == "True") {
            return true;
        }
        return false;

    }
    var SetupLoginPopup = function (container) {
        if (container == null) {
            container = $("body");
        }

        if (!IsUserLoggedIn()) {
            container.find(".actionContainerNeedsLogin").each(function () {
                var actionContainerNeedsLogin = $(this);

                var loginMessage = actionContainerNeedsLogin.data("logincontent") == null
                ? "You need to be logged in to use this feature. Click <a href='" + $(".entityLoginData").data("loginurl") + "'>here</a> to login."
                : actionContainerNeedsLogin.data("logincontent");

                actionContainerNeedsLogin.data("container", "body");
                actionContainerNeedsLogin.data("placement", "right");
                actionContainerNeedsLogin.data("content", loginMessage);
                actionContainerNeedsLogin.data("toggle", "popover");
                actionContainerNeedsLogin.data("html", "true");

                actionContainerNeedsLogin.popover();
            });
        }
    };
    //Set up logins
    SetupLoginPopup();


    $("body").on('click', '.discussionSaveButton', function (ev) {
        SaveDiscussion($(this), ev);
    });

    $("body").on('click', '.voteButton', function (ev) {
        VoteComment($(this), ev);
    });

    function LoadentityDiscussions() {
        var container = $(".entityDiscussionsContainer");
        ToggleLoader(container.data("loader"));
        $.post(container.data("url"), function (data) {
            if (data) {
                container.empty().html(data);
            }

            ToggleLoader(container.data("loader"));

            //Set up logins for any button that need it
            SetupLoginPopup(container);

            //Set up Focus on text areas on Collapibles when expanded
            SetupFocusOnCollapsible();
        });
    }

    function VoteComment(button, ev) {
        ev.preventDefault();

        if (IsUserLoggedIn()) {
            var scoreholder = button.data("scoreholder");
            $.post(button.attr("href"), function (data) {
                if (data.success) {
                    $(scoreholder).empty().html(data.score);
                }
            });
        }
    }

    function SaveDiscussion(button, ev) {
        ev.preventDefault();
        if (IsUserLoggedIn()) {
            var appr = $(".entityDiscussionsContainer").data("appr") == "True" ? true : false;
            var entityId = button.data("entity-id");
            var parent = button.data("parent");
            var child = button.data("child");
            var newText = $(parent).find(".newCommentText");
            var resultplacement = button.data("resultplacement") == null ? "replace" : button.data("resultplacement");
            var entityType = button.data("entity-type");
            var parentId = button.data("parent-id")

            if ($.trim(newText.val()).length == 0) {
                return;
            }

            ToggleLoader(button.data("loader"));

            if (parentId == null || parentId == "undefined") {
                passingData = { newText: newText.val(), entityId: entityId, entityType: entityType }
            } else {

                passingData = { newText: newText.val(), parentId: parentId }
            }



            var url = button.attr("href");
            $.ajax(url, {
                type: "POST",
                data: passingData,
                success: function (data) {
                    if (data && !appr) {
                        newText.val("");

                        //Focus on new inputs 
                        SetupFocusOnCollapsible();
                        if (data = "success") {
                            toastr.success("Your post was submitted for moderator approval.  Thank you!");
                        } else {
                            toastr.error('There was a problem saving your post.  Please try again.');
                        }

                        ToggleLoader(button.data("loader"));
                    } else {
                        toastr.error('There was a problem saving your post.  Please try again.');
                    }

                }
            });


            return true; //restore default
        }
    }

});