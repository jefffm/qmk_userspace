# ZMK to QMK Keymap Migration Plan

Goal: Port the ZMK `regret.keymap` layout to QMK `jmlynn` keymap.

## Summary of Differences

| Feature | ZMK (regret) | QMK (jmlynn) | Action |
|---------|--------------|--------------|--------|
| Layers | 7 (DEF, SYM, NAV, NUM, SYS, TMUX, GAME) | 4 (DEF, SYM, NAV, NUM) | Add 3 layers |
| Thumb layout | `BSPC NAV_LAYER SYM_LAYER SPACE` | `SPC BSPC NAV_LAYER SYM_LAYER SPC _` | **Fix thumb order** |
| SYS layer | Yes (combo-activated) | No | Add |
| TMUX layer | Yes (with macros) | No | Add |
| GAME layer | Yes | No | Add |
| RGB layer indicators | Yes | No | Skip (no RGB on skeletyl) |
| Combos | Extensive (brackets, shift, caps, esc, ret, sys) | None | Add combos |
| Home-row mods | Sticky keys on right home row | Oneshot mods | Keep OSM (simpler in QMK) |
| App/Window swapper | Yes (tri-state) | No | Skip (ZMK-specific) |
| Tmux macros | 30+ macros | None | Add |
| Lock screen key | Yes | No | Add |
| Caps word combo | Yes (0+9) | Via CW_TOGG | Keep QMK's way |

---

## Step-by-Step Tasks

### Step 1: Fix Thumb Row Order ⭐ HIGH PRIORITY
The ZMK thumb layout is: `BSPC | NAV | SYM | SPACE`
QMK currently has: `SPC | BSPC | NAV || SYM | SPC | _`

Update to match ZMK: left outer=BSPC, left inner=NAV, right inner=SYM, right outer=SPACE

**Files:** `keymap.c` (all layers)

---

### Step 2: Add Layer Definitions
Add layer enums for SYS, TMUX, GAME.

```c
enum layers {
    DEF,
    SYM,
    NAV,
    NUM,
    SYS,
    TMUX,
    GAME,
};
```

**Files:** `keymap.c`

---

### Step 3: Add Combos
Port these combos from ZMK:

| Combo | Keys | Action |
|-------|------|--------|
| `vlbkt` | 1+11 | `[` |
| `vlbrc` | 2+12 | `{` |
| `vlpar` | 3+13 | `(` |
| `vrpar` | 6+16 | `)` |
| `vrbrc` | 7+17 | `}` |
| `vrbkt` | 8+18 | `]` |
| `lshftc` | 2+3 | Sticky LSHIFT |
| `rshftc` | 6+7 | Sticky RSHIFT |
| `cw` | 0+9 | Caps Word |
| `caps` | 20+29 | Caps Lock |
| `esc` | 11+12+13 | ESC |
| `ret` | 16+17+18 | ENTER |
| `sys` | 30+33 | MO(SYS) |

**Files:** `keymap.c`, `rules.mk` (enable COMBO_ENABLE)

---

### Step 4: Update SYM Layer
Match ZMK layout (note: brackets moved to combos in ZMK):

```
Row 0: _       _       _       _       TILDE   CARET   _       EMOJI   to(TMUX) GRAVE
Row 1: MINUS   STAR    EQUAL   UNDER   DOLLAR  HASH    os_RSft os_RCtl os_RAlt  os_RGui
Row 2: PLUS    PIPE    AT      SLASH   PERCENT hackpipe BSLASH AMPER   QMARK    EXCL
Thumb: trans trans trans trans
```

**Files:** `keymap.c`

---

### Step 5: Update NAV Layer
Match ZMK layout (macOS mode for now, Windows can come later):

```
Row 0: _       swap*   win_swap* SSHOT  GLOBE*  TAB     HOME    UP      END     _
Row 1: os_LGui os_LAlt os_LCtl os_LSft BSPC   DELETE  LEFT    DOWN    RIGHT   _
Row 2: UNDO    CUT     COPY    PASTE   _       _       PGDN    _       PGUP    LOCK
Thumb: trans trans trans trans
```

*Note: swap/win_swap are ZMK tri-state behaviors - skip or implement as simple alt-tab.

**Files:** `keymap.c`

---

### Step 6: Update NUM Layer
Match ZMK (mostly same, add F6-F8 changes):

```
Row 0: 1       2       3       4       5       6       7       8       9       0
Row 1: os_LGui os_LAlt os_LCtl os_LSft F6      F7      os_RSft os_RCtl os_RAlt os_RGui
Row 2: F1      F2      F3      F4      F5      F8      F9      F10     F11     F12
Thumb: trans trans trans trans
```

**Files:** `keymap.c`

---

### Step 7: Add SYS Layer
New layer for system controls (activated via combo):

```
Row 0: BOOT    TG(GAME) _      _       _       _       PLAY    _       _       UNSTICK*
Row 1: GUI     ALT     CTRL    SHIFT   _       PREV    VOL_DN  VOL_UP  NEXT    _
Row 2: _       _       _       _       _       _       _       _       _       _
Thumb: trans trans trans trans
```

*UNSTICK = tap all mods to clear stuck state (can be a macro or skip)

**Files:** `keymap.c`

---

### Step 8: Add GAME Layer
Gaming layer with WASD-style layout:

```
Row 0: _       Q       W       E       R       LSHIFT  ENTER   UP      R       TO(DEF)
Row 1: _       A       S       D       F       _       LEFT    DOWN    RIGHT   S
Row 2: _       Z       X       C       V       _       _       _       _       _
Thumb: trans trans trans trans
```

**Files:** `keymap.c`

---

### Step 9: Add TMUX Layer (Optional)
Extensive tmux macro layer. Requires defining ~25 macros.

```
Row 0: tmux1   tmux2   tmux3   tmux4   tmux5   tmux6   tmux7   tmux8   tmux9   tmux0
Row 1: copy    vsplit  hsplit  pane_h  pane_j  pane_k  pane_l  zoom    close   new
Row 2: next    prev    detach  resize  layout  session window  rename  TO(DEF) break
Thumb: trans trans trans trans
```

**Files:** `keymap.c` (add macros section)

---

### Step 10: Add Hackpipe Macro
Already exists in QMK. Verify it sends `|> ` (with trailing space like ZMK).

**Files:** `keymap.c` (already done, verify)

---

### Step 11: Enable Required Features in rules.mk

```makefile
CAPS_WORD_ENABLE = yes
COMBO_ENABLE = yes
```

**Files:** `rules.mk`

---

## Features to Skip (ZMK-specific)

1. **RGB layer indicators** - Skeletyl doesn't have per-key RGB
2. **Tri-state swapper** - Complex ZMK behavior, use simple alt-tab instead
3. **Bluetooth controls** - QMK wired, not needed
4. **Platform switching** - Start with one platform (macOS or Windows)

---

## Recommended Execution Order

1. **Step 1** - Fix thumb row (foundational)
2. **Step 2** - Add layer enums
3. **Step 11** - Enable rules.mk features
4. **Step 3** - Add combos (bracket combos are critical for usability)
5. **Steps 4-6** - Update SYM, NAV, NUM layers
6. **Step 7** - Add SYS layer
7. **Step 8** - Add GAME layer
8. **Step 9** - Add TMUX layer (can be last, most complex)

---

## Testing

After each step:
```bash
qmk compile -kb bastardkb/skeletyl/v2/splinky_3 -km jmlynn
```
