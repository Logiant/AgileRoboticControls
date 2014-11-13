function IsUserLoggedIn() {
    if ($(".learningObjectLoginData").data("loggedin") == "True") {
        return true;
    }
    else {
        return false;
    }
}

var SetupLoginPopup = function (container) {
    if (container == null) {
        container = $("body");
    }

    if (!IsUserLoggedIn()) {

        var loginPopoverContent = $("#loginPopoverContent");

        container.find(".actionContainerNeedsLogin").each(function () {
            var actionContainerNeedsLogin = $(this);

            var loginMessage = actionContainerNeedsLogin.data("logincontent") || loginPopoverContent.html();

            actionContainerNeedsLogin.data("container", "body");
            actionContainerNeedsLogin.data("placement", "right");
            actionContainerNeedsLogin.data("content", loginMessage);
            actionContainerNeedsLogin.data("toggle", "popover");
            actionContainerNeedsLogin.data("html", "true");

            actionContainerNeedsLogin.popover();
        });
    }
};

//var SetupFocusOnCollapsible = function () {
//    $('.learningObjectNewDiscussionCollapsible, .learningObjectNewQuestionCommentCollapsible, .learningObjectNewAnswerCommentCollapsible, .learningObjectAnswerThisQuestionCollapsible, .learningObjectNewQuestionCollapsible, .learningObjectAnswerCommentsCollapsible, .replyCommentButtonCollapsible')
//        .on('shown.bs.collapse', function () {
//            $(this).find(".newCommentText").focus();
//        });
//};

var SetupAddToGroupsPopup = function () {

    var addToGroupSection = $(".agSection");
    if (IsUserLoggedIn()) {
        //addToGroupSection.data("content", $(".agPopoverContentContainer").html());
        addToGroupSection.popover({
            content: function () {
                return $(".agPopoverContentContainer").html()
            }
        });

    }
};

$(function () {

    //Set up logins
    SetupLoginPopup();

    //For adding this LO to a Group
    SetupAddToGroupsPopup();

    //Load LO Discussions ajax style
    //LoadLearningObjectDiscussions();

    //Set up event handlers

    var rateButtons = $(".rateLearningObject");

    rateButtons.click(function (ev) {
        ev.preventDefault();

        var button = $(this);

        var container = $(".voteCount");

        var isUpVoteButton = button.data().votePositive || false;

        container.removeClass("in");


        $.post(button.attr("href"), function (data) {
            if (data.success) {
                var count = (data.upvotecount - data.downvotecount);

                container.empty().html(count);

                rateButtons.removeClass("btn-success").removeClass("btn-danger").addClass("btn-default");

                if (data.userVote != null) {
                    if (isUpVoteButton && data.userVote) {
                        button.addClass("btn-success").removeClass("btn-default");
                    }
                    else if (!isUpVoteButton && !data.userVote) {
                        button.addClass("btn-danger").removeClass("btn-default");
                    }
                }
            }
            container.addClass("in");
        });

        return false;
    });

    $("body").on('click', '.discussionSaveButton', function (ev) {
        SaveDiscussion($(this), ev);
    });

    $("body").on('click', '.voteButton', function (ev) {
        VoteComment($(this), ev);
    });

    $("body").on('click', '.agSubmit', function (ev) {
        ev.preventDefault();

        UpdateLearningObjectGroup($(this), ev);

        return false;
    });

    $("body").on('click', '.agCloseButton', function (ev) {
        $($(this).data("dismiss")).popover("hide");
        $(".popover").hide(); //this will ensure the links still work!
    });


    var mustBeLoggedInPopoverContent = $("#mustBeLoggedInPopoverContent");

    $(".actionNeedsLogin").each(function () {
        $(this).popover({
            trigger: "focus",
            content: mustBeLoggedInPopoverContent.html(),
            html: true,
            container: "body"
        });
    })
    //.click(function (e) {
    //    e.preventDefault();
    //    $(this).popover("toggle");
    //    return false;
    //});


    var userGroupsMenu = $("#userGroupsMenu");
    function UpdateLearningObjectGroup(button, ev) {

        var inputSource = button.parent().find($(button.data("inputsource")));
        var outputSource = button.data("outputsource");

        var groupName = inputSource != null ? inputSource.val() : null;

        $(button.data("loader")).removeClass("hidden");

        $.post(button.attr("href"), { groupName: groupName }, function (data) {
            if (data) {
                inputSource.val("");
                userGroupsMenu.html(data);
            }

            //when all done, get rid of the ajax loader
            $(button.data("loader")).addClass("hidden");
        });
    }


    var newGroupModal = $("#newGroupModal");

    $("#createNewGroupButton").click(function (e) {

        var button = $(this);

        var data = {
            groupName: $("#newGroupNameTextBox").val(),
            id: button.data("learningObjectId"),
            groupId: 0
        };

        if (data.groupName) {

            var url = button.data("href");

            $(".agLoader").removeClass("hidden");
            $.post(url, data, function (data) {
                if (data) {
                    userGroupsMenu.html(data);
                }

                //when all done, get rid of the ajax loader
                $(".agLoader").addClass("hidden");
            });

            newGroupModal.modal("hide");
        }
    });

    newGroupModal.on("hidden.bs.modal", function (e) {
        $("#newGroupNameTextBox").val("");
    });



    //function LoadLearningObjectDiscussions() {
    //    var container = $(".learningObjectDiscussionsContainer");
    //    ToggleLoader(container.data("loader"));
    //    $.post(container.data("url"), function (data) {
    //        if (data) {
    //            container.empty().html(data);
    //        }

    //        ToggleLoader(container.data("loader"));

    //        //Set up logins for any button that need it
    //        SetupLoginPopup(container);

    //        //Set up Focus on text areas on Collapibles when expanded
    //        SetupFocusOnCollapsible();
    //    });
    //}

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
            var appr = $(".learningObjectDiscussionsContainer").data("appr") == "True" ? true : false;
            var parent = button.data("parent");
            var child = button.data("child");
            var newText = $(parent).find(".newCommentText");
            var resultplacement = button.data("resultplacement") == null ? "replace" : button.data("resultplacement");

            if ($.trim(newText.val()).length == 0) {
                return;
            }

            ToggleLoader(button.data("loader"));

            $.post(button.attr("href"), { newText: newText.val() }, function (data) {
                if (data && !appr) {
                    //data.hide();
                    resultplacement == "append"
                        ? $(child).append(data)
                        : resultplacement == "prepend"
                        ? $(child).prepend(data)
                        : $(child).empty().html(data);
                    newText.val("");

                    //Focus on new inputs 
                    SetupFocusOnCollapsible();
                }

                //ajax loader gone!
                ToggleLoader(button.data("loader"));
            });

            if (appr) {
                alert("Thank you. Your comment has been submitted and will be reviewed by Wisc-online moderators before being displayed.");
            }

            return true; //restore default
        }
    }



});