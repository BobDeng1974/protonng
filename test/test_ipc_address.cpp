/*
 * Copyright (c) 2018 Matt Gigli
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE
 * SOFTWARE.
 */

#include <gtest/gtest.h>
#include <string>

#include "protonng/ipc_address.hpp"

TEST(IpcAddressTest, Loopback) {
    protonng::IpcAddress ipc_addr("/tmp/ipc-test");
    EXPECT_EQ(ipc_addr.addr(), "ipc:///tmp/ipc-test");
    EXPECT_EQ(ipc_addr.transport(), "ipc");
}

TEST(IpcAddressCopy, CopyConstructor) {
  protonng::IpcAddress tcp_addr1("/tmp/ipc-test");
  protonng::IpcAddress tcp_addr2(tcp_addr1);
  EXPECT_EQ(tcp_addr1.addr(), "ipc:///tmp/ipc-test");
  EXPECT_EQ(tcp_addr2.addr(), "ipc:///tmp/ipc-test");
}

TEST(IpcAddressCopy, CopyAssignment) {
  protonng::IpcAddress tcp_addr1("/tmp/ipc-test");
  protonng::IpcAddress tcp_addr2 = tcp_addr1;
  EXPECT_EQ(tcp_addr1.addr(), "ipc:///tmp/ipc-test");
  EXPECT_EQ(tcp_addr2.addr(), "ipc:///tmp/ipc-test");
}

TEST(IpcAddressMove, MoveConstructor) {
  protonng::IpcAddress tcp_addr1("/tmp/ipc-test");
  protonng::IpcAddress tcp_addr2(std::move(tcp_addr1));
  EXPECT_EQ(tcp_addr1.addr(), "");
  EXPECT_EQ(tcp_addr2.addr(), "ipc:///tmp/ipc-test");
}

TEST(IpcAddressMove, MoveAssignment) {
  protonng::IpcAddress tcp_addr1("/tmp/ipc-test");
  protonng::IpcAddress tcp_addr2 = std::move(tcp_addr1);
  EXPECT_EQ(tcp_addr1.addr(), "");
  EXPECT_EQ(tcp_addr2.addr(), "ipc:///tmp/ipc-test");
}
