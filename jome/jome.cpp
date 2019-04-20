/*
 * Copyright (C) 2019 Philippe Proulx <eepp.ca>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license. See the LICENSE file for details.
 */

#include <QApplication>
#include <QLabel>
#include <cstdio>

#include "emoji-db.hpp"
#include "emoji-images.hpp"

int main(int argc, char **argv)
{
#if 0
    QApplication app {argc, argv};

    jome::EmojiDb db {JOME_DATA_DIR};
    jome::EmojiImages images {db};
    auto& emoji = db.emojiForStr("🦊");

    QLabel lbl {""};
    lbl.resize(32, 32);
    lbl.setPixmap(images.pixmapForEmoji(emoji));
    lbl.show();
    return app.exec();
#endif

    std::vector<const jome::Emoji *> emojis;

    jome::EmojiDb db {JOME_DATA_DIR};
    db.findEmojis(argv[1], argv[2], emojis);

    for (const auto emoji : emojis) {
        std::printf("%s    %s (%p)\n", emoji->str().c_str(),
                    emoji->name().c_str(), emoji);
    }
}
