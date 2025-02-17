//
// Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com) 2014-2021
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
#pragma once

#include "td/db/SqliteKeyValueSafe.h"

#include "td/actor/PromiseFuture.h"

#include <memory>
#include <unordered_map>

namespace td {

class SqliteKeyValueAsyncInterface {
 public:
  virtual ~SqliteKeyValueAsyncInterface() = default;

  virtual void set(string key, string value, Promise<Unit> promise) = 0;

  virtual void set_all(std::unordered_map<string, string> key_values, Promise<Unit> promise) = 0;

  virtual void erase(string key, Promise<Unit> promise) = 0;

  virtual void erase_by_prefix(string key_prefix, Promise<Unit> promise) = 0;

  virtual void get(string key, Promise<string> promise) = 0;

  virtual void close(Promise<Unit> promise) = 0;
};

unique_ptr<SqliteKeyValueAsyncInterface> create_sqlite_key_value_async(std::shared_ptr<SqliteKeyValueSafe> kv,
                                                                       int32 scheduler_id = 1);
}  // namespace td
