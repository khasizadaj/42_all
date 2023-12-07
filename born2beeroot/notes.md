# Notes

- What is ISO Image?
    - An ISO image for a virtual machine is like a digital copy of a DVD that you can use on your computer. Instead of putting a DVD into a physical DVD player, you can use this digital copy to set up a new virtual computer inside your real computer. It's like having a DVD that you can use over and over again without needing the physical disc.

- What is partition?
- What is LVM?
- What is GRB boot loader?
- What is `sudo visudo` used for?
    - Why this was needed `jkhasiza  ALL=(ALL) ALL`?
--- 

```bash
# login as root user; will prompt root user pass
su -

# add user to the group
usermod -aG {user_group} {username}
# e.g.: usermod -aG sudo jkhasiza
```

---

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
- `sudo adduser {username}`
- `chage -l {username}`
    - `chage` is used to change password expiration date
    - above command just is used to get account aging information
- `usermod -aG {username} {group_name}`
- `sudo groupadd {group_name}`
    - create new group
- `{username}  	ALL=(ALL) ALL` - inside `sudoers`
	- can be accessed via `sudo visudo`
	- this line allows that user to run any command on any machine as any other user (including as the root user) using sudo. This is a very powerful privilege and should be granted with care, as it essentially gives the user complete control over the system.
- `apt` vs `apt-get`
    - https://aws.amazon.com/compare/the-difference-between-apt-and-apt-get/

- getting manual page for `libpam-pwquality` password policy
    - man pwquality.conf