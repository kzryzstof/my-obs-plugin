#include "unity.h"

#include "text/parsers.h"

#include <string.h>

void setUp(void) {}
void tearDown(void) {}

static void is_presence_message__message_is_null_false_returned(void) {
    //  Arrange.
    const char *message = NULL;

    //  Act.
    bool actual = is_presence_message(message);

    //  Assert.
    TEST_ASSERT_FALSE(actual);
}

static void is_presence_message__message_is_empty_false_returned(void) {
    //  Arrange.
    const char *message = " ";

    //  Act.
    bool actual = is_presence_message(message);

    //  Assert.
    TEST_ASSERT_FALSE(actual);
}

static void is_presence_message__message_is_not_json_false_returned(void) {
    //  Arrange.
    const char *message = "this-is-not-a-json";

    //  Act.
    bool actual = is_presence_message(message);

    //  Assert.
    TEST_ASSERT_FALSE(actual);
}

static void is_presence_message__message_is_achievement_false_returned(void) {
    //  Arrange.
    const char *message =
        "{\"serviceConfigId\":\"00000000-0000-0000-0000-00007972ac43\",\"progression\":[{\"id\":\"1\",\"requirements\":[{\"id\":\"00000000-0000-0000-0000-000000000000\",\"current\":\"100\",\"target\":\"100\",\"operationType\":\"Sum\",\"valueType\":\"Integer\",\"ruleParticipationType\":\"Individual\"}],\"progressState\":\"Achieved\",\"timeUnlocked\":\"2026-01-18T02:48:21.707Z\"}],\"contractVersion\":1}";

    //  Act.
    bool actual = is_presence_message(message);

    //  Assert.
    TEST_ASSERT_FALSE(actual);
}

static void is_presence_message__message_is_presence_true_returned(void) {
    //  Arrange.
    const char *message =
        "{\"devicetype\":\"XboxOne\",\"titleid\":0,\"string1\":\"Vu en dernier il y a 1 min : Application Xbox\",\"string2\":\"\",\"presenceState\":\"Offline\",\"presenceText\":\"Vu en dernier il y a 1 min : Application Xbox\",\"presenceDetails\":[{\"isBroadcasting\":false,\"device\":\"iOS\",\"presenceText\":\"Vu en dernier il y a 1 min : Application Xbox\",\"state\":\"LastSeen\",\"titleId\":\"328178078\",\"isGame\":false,\"isPrimary\":true,\"richPresenceText\":\"\"}],\"xuid\":2533274953419891}";

    //  Act.
    bool actual = is_presence_message(message);

    //  Assert.
    TEST_ASSERT_TRUE(actual);
}

static void is_achievement_message__message_is_null_false_returned(void) {
    //  Arrange.
    const char *message = NULL;

    //  Act.
    bool actual = is_achievement_message(message);

    //  Assert.
    TEST_ASSERT_FALSE(actual);
}

static void is_achievement_message__message_is_empty_false_returned(void) {
    //  Arrange.
    const char *message = " ";

    //  Act.
    bool actual = is_achievement_message(message);

    //  Assert.
    TEST_ASSERT_FALSE(actual);
}

static void is_achievement_message__message_is_not_json_false_returned(void) {
    //  Arrange.
    const char *message = "this-is-not-a-json";

    //  Act.
    bool actual = is_achievement_message(message);

    //  Assert.
    TEST_ASSERT_FALSE(actual);
}

static void is_achievement_message__message_is_achievement_true_returned(void) {
    //  Arrange.
    const char *message =
        "{\"serviceConfigId\":\"00000000-0000-0000-0000-00007972ac43\",\"progression\":[{\"id\":\"1\",\"requirements\":[{\"id\":\"00000000-0000-0000-0000-000000000000\",\"current\":\"100\",\"target\":\"100\",\"operationType\":\"Sum\",\"valueType\":\"Integer\",\"ruleParticipationType\":\"Individual\"}],\"progressState\":\"Achieved\",\"timeUnlocked\":\"2026-01-18T02:48:21.707Z\"}],\"contractVersion\":1}";

    //  Act.
    bool actual = is_achievement_message(message);

    //  Assert.
    TEST_ASSERT_TRUE(actual);
}

static void is_achievement_message__message_is_presence_false_returned(void) {
    //  Arrange.
    const char *message =
        "{\"devicetype\":\"XboxOne\",\"titleid\":0,\"string1\":\"Vu en dernier il y a 1 min : Application Xbox\",\"string2\":\"\",\"presenceState\":\"Offline\",\"presenceText\":\"Vu en dernier il y a 1 min : Application Xbox\",\"presenceDetails\":[{\"isBroadcasting\":false,\"device\":\"iOS\",\"presenceText\":\"Vu en dernier il y a 1 min : Application Xbox\",\"state\":\"LastSeen\",\"titleId\":\"328178078\",\"isGame\":false,\"isPrimary\":true,\"richPresenceText\":\"\"}],\"xuid\":2533274953419891}";

    //  Act.
    bool actual = is_achievement_message(message);

    //  Assert.
    TEST_ASSERT_FALSE(actual);
}

int main(void) {
    UNITY_BEGIN();
    //  Test is_presence_message
    RUN_TEST(is_presence_message__message_is_null_false_returned);
    RUN_TEST(is_presence_message__message_is_empty_false_returned);
    RUN_TEST(is_presence_message__message_is_not_json_false_returned);
    RUN_TEST(is_presence_message__message_is_achievement_false_returned);
    RUN_TEST(is_presence_message__message_is_presence_true_returned);
    //  Test is_achievement_message
    RUN_TEST(is_achievement_message__message_is_null_false_returned);
    RUN_TEST(is_achievement_message__message_is_empty_false_returned);
    RUN_TEST(is_achievement_message__message_is_not_json_false_returned);
    RUN_TEST(is_achievement_message__message_is_achievement_true_returned);
    RUN_TEST(is_achievement_message__message_is_presence_false_returned);
    return UNITY_END();
}
