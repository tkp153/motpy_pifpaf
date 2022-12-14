from setuptools import setup

package_name = 'motpy_pifpaf'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='root',
    maintainer_email='takap365best@gmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'motpy_pifpaf = motpy_pifpaf.motpy_pifpaf:main',
            'motpy_pifpafv2 = motpy_pifpaf.motpy_pifpafv2:main',
            'rgbd_motpy_pifpaf = motpy_pifpaf.rgbd_motpy_pifpaf:main',
            'motpy_check = motpy_check.motpy_check:main',
        ],
    },
)
