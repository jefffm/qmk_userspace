# CLAUDE.md - QMK Userspace Project Guide

Project-specific instructions for working in this QMK Userspace repository.

## What This Repository Is

This is a **QMK Userspace** repository containing custom keymaps for multiple keyboards:
- Bastard Keyboards Skeletyl (split 3x5+3 layout)
- BeeKeeb Piantor
- Kinesis Advantage

The main QMK firmware lives in `../qmk_firmware`. This repo contains user-specific customizations.

## Testing Protocol

**CRITICAL**: After ANY changes to keymap files, you MUST test compilation before committing:

```bash
qmk compile -kb bastardkb/skeletyl/v2/splinky_3 -km jmlynn
```

Replace the keyboard path with the appropriate one for the keymap you're modifying.

## Active Migration Project

There is an active migration from ZMK to QMK for the Skeletyl keyboard. See:
- `keyboards/bastardkb/skeletyl/keymaps/jmlynn/MIGRATION_PLAN.md`

When working on migration tasks:
1. Follow the step-by-step plan in MIGRATION_PLAN.md
2. Test compilation after each step
3. Update the plan if you discover issues or changes needed
4. Mark steps as complete in commit messages

## Keyboard-Specific Notes

### Skeletyl
- **Controller**: Splinky v3 (RP2040)
- **Layout**: 3x5 split + 3 thumb keys per side
- **Features**: RGB matrix, split keyboard, oneshot mods
- **Compile**: `qmk compile -kb bastardkb/skeletyl/v2/splinky_3 -km jmlynn`
- **Active work**: Porting layout from ZMK

### Piantor
- **Controller**: TBD
- **Layout**: Similar to Skeletyl
- **Compile**: `qmk compile -kb beekeeb/piantor -km jmlynn`

### Kinesis
- **Controller**: Kinesis Advantage
- **Compile**: `qmk compile -kb kinesis -km jmlynn`

## Development Workflow

1. **Read** the relevant keymap file before making changes
2. **Edit** the keymap following QMK conventions
3. **Compile** to verify changes: `qmk compile -kb <keyboard> -km jmlynn`
4. **Review** the output for errors or warnings
5. **Commit** only after successful compilation
6. **Reference** file locations in commit messages (e.g., `keymap.c:53`)

## Common Pitfalls

- Don't commit without compiling first
- Missing `SAFE_RANGE` in custom keycode enums
- Forgetting to enable features in `rules.mk` (e.g., `COMBO_ENABLE = yes`)
- Layer count mismatches (enum vs actual layer definitions)
- Using `KC_NO` when `XXXXXXX` is more appropriate
- Missing include guards or `#pragma once`

## Useful Patterns in This Codebase

### Oneshot Modifiers
```c
#define OS_LSFT OSM(MOD_LSFT)
#define OS_LCTL OSM(MOD_LCTL)
// ... etc
```

### Layer Access
```c
#define LA_SYM MO(SYM)  // Momentary layer
#define LA_NAV MO(NAV)
```

### Tri-layer Activation
```c
layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, SYM, NAV, NUM);
}
```

## Dependencies

Ensure QMK Python dependencies are installed:
```bash
/opt/homebrew/Cellar/qmk/1.1.8/libexec/bin/python -m pip install -r /Users/jeff/qmk_firmware/requirements.txt
```

## Related Files

- Main firmware repo: `../qmk_firmware`
- Global agent instructions: `~/.claude/CLAUDE.md`
- Agent guidelines: `AGENTS.md` (this repo)
