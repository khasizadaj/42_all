
- get iso file
- set location for created VMs
- give it a name
- choose OS
- choose distribution
- add ISO file for created VM

https://github.com/pasqualerossi/Born2BeRoot-Guide

## NOtes

- `/etc/ssh/sshd_config` should be updated to allow certain ports be accesible by users via ssh connection


## Useful stuff

- `getent`
	- `getent` is a command-line utility available on Unix and Linux systems. It is used to fetch entries from databases supported by the Name Service Switch (NSS) libraries, which are configured in /etc/nsswitch.conf. These databases can include, but are not limited to, users (`passwd`), groups (`group`), and hosts (`hosts`).

- `usermod -aG {username} {group_name}`
- `{username}  	ALL=(ALL) ALL` - inside `sudoers`
	- can be accessed via `sudo visudo`
	- this line allows that user to run any command on any machine as any other user (including as the root user) using sudo. This is a very powerful privilege and should be granted with care, as it essentially gives the user complete control over the system.
- 