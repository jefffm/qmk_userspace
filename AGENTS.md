# AGENTS.md - QMK Userspace

Guidelines for AI coding agents working in this QMK Userspace repository.

## Testing Changes

### Compile Specific Keymap
After making any changes to a keymap, ALWAYS compile to verify the changes work:

```bash
# Test skeletyl jmlynn keymap
qmk compile -kb bastardkb/skeletyl/v2/splinky_3 -km jmlynn

# Test kinesis jmlynn keymap
qmk compile -kb kinesis -km jmlynn

# Test piantor jmlynn keymap
qmk compile -kb beekeeb/piantor -km jmlynn
```

### Test All Keymaps
```bash
# Compile all keymaps for a specific keyboard
qmk compile -kb bastardkb/skeletyl/v2/splinky_3 -km all
```

## Repository Structure

```
keyboards/
  bastardkb/skeletyl/keymaps/jmlynn/    # Skeletyl custom keymap
  beekeeb/piantor/keymaps/jmlynn/       # Piantor custom keymap
  kinesis/keymaps/jmlynn/               # Kinesis custom keymap
users/jmlynn/                           # Shared code across keymaps
```

## Task Management

This project uses a CLI ticket system for task management. Run `tk help` when you need to use it.

Common tk commands:
```bash
# List ready tasks (no blockers)
tk ready

# Show blocked tasks
tk blocked

# Show a specific ticket
tk show <id>

# Create a new task
tk create "Task title" -d "Description" -t task

# Start working on a task
tk start <id>

# Close a completed task
tk close <id>
```

## Important Notes

- **ALWAYS compile after making changes** to verify syntax and configuration
- This is a QMK userspace repo - it contains only user-specific keymaps
- The main QMK firmware is in `../qmk_firmware`
- Changes here override the default QMK firmware keymaps
- Use the migration plans (e.g., `MIGRATION_PLAN.md`) when porting layouts

## QMK Userspace Workflow

1. Make changes to keymap files in `keyboards/*/keymaps/jmlynn/`
2. Test compilation with `qmk compile`
3. If successful, commit changes
4. Flash to keyboard: `qmk flash -kb <keyboard> -km jmlynn`

## Common Commands

```bash
# Compile specific keymap
qmk compile -kb <keyboard> -km jmlynn

# Flash to keyboard (enters bootloader mode)
qmk flash -kb <keyboard> -km jmlynn

# List available keyboards
qmk list-keyboards

# List available keymaps for a keyboard
qmk list-keymaps -kb <keyboard>
```

## Code Style

Follow QMK conventions:
- Use `#pragma once` in headers
- 4-space indentation
- Layer names in UPPER_CASE
- Custom keycodes use `KC_` prefix
- Use meaningful macro names (e.g., `OS_LSFT` for oneshot shift)

## Testing Checklist

Before committing keymap changes:
- [ ] Code compiles without errors
- [ ] Layer definitions are complete
- [ ] Custom keycodes are properly defined
- [ ] Rules.mk includes required features
- [ ] Changes follow existing code patterns
