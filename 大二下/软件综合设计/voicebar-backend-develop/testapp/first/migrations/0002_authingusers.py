# Generated by Django 4.1 on 2022-08-09 15:48

from django.conf import settings
from django.db import migrations, models
import django.db.models.deletion


class Migration(migrations.Migration):

    dependencies = [
        migrations.swappable_dependency(settings.AUTH_USER_MODEL),
        ('first', '0001_initial'),
    ]

    operations = [
        migrations.CreateModel(
            name='AuthingUsers',
            fields=[
                ('sub', models.CharField(max_length=50, primary_key=True, serialize=False)),
                ('user', models.ForeignKey(on_delete=django.db.models.deletion.CASCADE, to=settings.AUTH_USER_MODEL)),
            ],
        ),
    ]
