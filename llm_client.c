/*
 * llm_client.c — HTTP+JSON glue between the Agent and the LLM service.
 *
 * Your job: implement llm_chat. Everything else in this file is yours to
 * design. You will certainly want helpers (request construction, response
 * parsing, …); whether and how you decompose them is a decision for you.
 */
#include "llm_client.h"

#include "config.h"
#include "http.h"
#include "tools/tools.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define LLM_TIMEOUT_SEC 120

int llm_chat(const MessageList *messages, const char *system_prompt,
             const char *model, LLMResponse *out, char *err, size_t err_cap) {
  (void)messages;
  (void)system_prompt;
  (void)model;
  (void)out;

  /*
   * TODO(student, Part 1A):
   *
   * 1. Build the request body. It is a JSON object with fields
   *    `model`, `messages` (system prompt prepended to the given list),
   *    `tools` (one entry describing the bash tool — see BASH_TOOL_NAME /
   *    BASH_TOOL_DESC / BASH_TOOL_SCHEMA in tools/tools.h), and
   *    `max_tokens` (g_config.max_tokens). Use cJSON (see libs/cJSON.h);
   *    hand-splicing strings will not scale.
   *
   * 2. Open a TCP connection (see http.h) and send a POST to
   *    /api/v1/chat/completions with Authorization: Bearer <api_key>.
   *
   * 3. Read the full response with recv_all, parse it with
   *    http_parse_response, and reject any non-200 status.
   *
   * 4. Parse the JSON body. The assistant message lives at
   *    choices[0].message. Extract `content` (may be missing or empty)
   *    and every entry of `tool_calls` (each has `id`, `function.name`,
   *    `function.arguments`). `arguments` arrives as a JSON *string* on
   *    the wire — cJSON_Parse it back into an object. If the string is
   *    empty, treat it as an empty object.
   *
   * 5. Also keep a serialized copy of the whole assistant message
   *    (cJSON_PrintUnformatted is convenient) in out->raw_message — the
   *    agent will push it into history verbatim so the LLM sees its own
   *    previous reply on the next call.
   *
   * Everything you malloc / cJSON_Parse here has to be freed somewhere.
   * Decide where. `make asan` will tell you if you got it wrong.
   */

  snprintf(err, err_cap, "llm_chat not implemented yet");
  return -1;
}
